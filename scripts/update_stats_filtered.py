from __future__ import annotations

import json
import re
from collections import defaultdict
from datetime import date, datetime
from pathlib import Path
from typing import Any


# =========================
# 基本設定
# =========================

PROBLEMS_DIR = Path("docs/problems")
README_PATH = Path("README.md")
KNOWLEDGE_PATH = Path("stats/skillmap.json")

STATS_START = "<!-- STATS_START -->"
STATS_END = "<!-- STATS_END -->"

MISTAKES_START = "<!-- MISTAKES_START -->"
MISTAKES_END = "<!-- MISTAKES_END -->"

# 四個能力的權重，總和必須為 1
WEIGHTS = {
    "independent": 0.30,
    "understanding": 0.25,
    "implementation": 0.25,
    "recognition": 0.20,
}


# =========================
# 文字解析
# =========================

def get_field(text: str, field_name: str) -> str | None:
    """
    取得指定欄位的文字。

    例如：
        Tags: 2d_prefix_sum, 1d_prefix_sum
        Independent: 1

    也支援：
        // Tags: ...
        * Tags: ...
    """

    pattern = re.compile(
        rf"^\s*(?://\s*|\*\s*)?"
        rf"{re.escape(field_name)}\s*:\s*(.*?)\s*$",
        flags=re.MULTILINE | re.IGNORECASE,
    )

    match = pattern.search(text)

    if match is None:
        return None

    return match.group(1).strip()


def get_integer_field(
    text: str,
    field_name: str,
    minimum: int = 1,
    maximum: int = 5,
) -> int | None:
    """
    讀取整數欄位，並檢查是否位於合法範圍。
    """

    value = get_field(text, field_name)

    if value is None:
        return None

    try:
        number = int(value)
    except ValueError:
        return None

    if not minimum <= number <= maximum:
        return None

    return number


def get_date_field(text: str, field_name: str) -> date | None:
    """
    讀取 YYYY-MM-DD 日期。
    """

    value = get_field(text, field_name)

    if value is None:
        return None

    try:
        return datetime.strptime(value, "%Y-%m-%d").date()
    except ValueError:
        return None


def split_list_field(value: str | None) -> list[str]:
    """
    將逗號分隔欄位拆成 list。

    例如：
        2d_prefix_sum, 1d_prefix_sum

    會得到：
        ["2d_prefix_sum", "1d_prefix_sum"]
    """

    if value is None:
        return []

    result = []

    for item in value.split(","):
        item = normalize_name(item)

        if item:
            result.append(item)

    return result


def normalize_name(name: str) -> str:
    """
    移除前後空白，並將連續空白合併。
    """

    return re.sub(r"\s+", " ", name.strip())


# =========================
# 單一題目解析
# =========================

def parse_problem(path: Path) -> dict[str, Any] | None:
    text = path.read_text(encoding="utf-8")

    tags = split_list_field(get_field(text, "Tags"))

    if not tags:
        print(f"[警告] 找不到 Tags：{path}")
        return None

    problem_date = get_date_field(text, "Date")

    if get_field(text, "Date") is not None and problem_date is None:
        print(f"[警告] Date 格式錯誤：{path}")

    scores = {
        "independent": get_integer_field(
            text,
            "Independent",
        ),
        "understanding": get_integer_field(
            text,
            "Understanding",
        ),
        "implementation": get_integer_field(
            text,
            "Implementation",
        ),
        "recognition": get_integer_field(
            text,
            "Recognition",
        ),
    }

    for score_name, score in scores.items():
        if score is None:
            print(
                f"[警告] {path} 的 {score_name} "
                "不存在、不是整數或不在 1～5"
            )

    mistakes = split_list_field(
        get_field(text, "Mistakes")
    )

    return {
        "path": str(path),
        "date": problem_date,
        "tags": tags,
        "mistakes": mistakes,
        **scores,
    }



# =========================
# Skill 白名單
# =========================

def load_valid_skills() -> set[str]:
    """
    從 knowledge_points.json 載入合法 skill。

    支援以下兩種 JSON 格式：

    1. 依分類整理：
       {
         "prefix_sum": ["1d_prefix_sum", "2d_prefix_sum"],
         "graph": ["bfs", "dfs"]
       }

    2. 純陣列：
       [
         "1d_prefix_sum",
         "2d_prefix_sum",
         "bfs"
       ]

    回傳所有合法 skill 的集合。
    """

    if not KNOWLEDGE_PATH.exists():
        raise FileNotFoundError(
            f"找不到 skill 清單：{KNOWLEDGE_PATH}"
        )

    with KNOWLEDGE_PATH.open(encoding="utf-8") as file:
        raw_data = json.load(file)

    valid_skills: set[str] = set()

    if isinstance(raw_data, dict):
        for category, skills in raw_data.items():
            if not isinstance(skills, list):
                raise ValueError(
                    f"{KNOWLEDGE_PATH} 中分類 {category!r} "
                    "的內容必須是陣列"
                )

            for skill in skills:
                if not isinstance(skill, str):
                    raise ValueError(
                        f"{KNOWLEDGE_PATH} 中出現非字串 skill："
                        f"{skill!r}"
                    )

                normalized = normalize_name(skill)

                if normalized:
                    if normalized in valid_skills:
                        raise ValueError(
                            f"skill 重複出現在 JSON 中：{normalized}"
                        )

                    valid_skills.add(normalized)

    elif isinstance(raw_data, list):
        for skill in raw_data:
            if not isinstance(skill, str):
                raise ValueError(
                    f"{KNOWLEDGE_PATH} 中出現非字串 skill："
                    f"{skill!r}"
                )

            normalized = normalize_name(skill)

            if normalized:
                if normalized in valid_skills:
                    raise ValueError(
                        f"skill 重複出現在 JSON 中：{normalized}"
                    )

                valid_skills.add(normalized)

    else:
        raise ValueError(
            f"{KNOWLEDGE_PATH} 最外層必須是物件或陣列"
        )

    if not valid_skills:
        raise ValueError(
            f"{KNOWLEDGE_PATH} 中沒有任何合法 skill"
        )

    return valid_skills


# =========================
# 收集所有資料
# =========================

def collect_statistics() -> tuple[dict, dict]:
    """
    只統計 knowledge_points.json 中有登記的 skill。

    回傳：
        tag_statistics
        mistake_statistics
    """

    valid_skills = load_valid_skills()

    # 先替 JSON 中的所有 skill 建立空資料。
    # 如此從未在任何題目中出現的 skill 也能顯示在 README。
    tag_statistics = {
        skill: {
            "problem_count": 0,
            "evaluated_count": 0,
            "independent": [],
            "understanding": [],
            "implementation": [],
            "recognition": [],
            "mistakes": defaultdict(int),
            "last_date": None,
        }
        for skill in valid_skills
    }

    mistake_statistics = defaultdict(int)

    if not PROBLEMS_DIR.exists():
        raise FileNotFoundError(
            f"找不到題目資料夾：{PROBLEMS_DIR}"
        )

    cpp_files = sorted(PROBLEMS_DIR.rglob("*.cpp"))

    if not cpp_files:
        print(f"[警告] {PROBLEMS_DIR} 中沒有找到 .cpp")

    for path in cpp_files:
        problem = parse_problem(path)

        if problem is None:
            continue

        # 只保留 JSON 白名單中的 skill
        problem_skills = {
            tag
            for tag in problem["tags"]
            if tag in valid_skills
        }

        # 顯示被忽略的未登記 Tag，方便找拼字錯誤
        ignored_tags = sorted(
            set(problem["tags"]) - problem_skills
        )

        for tag in ignored_tags:
            print(
                f"[忽略] {path} 中未登記的 Tag：{tag}"
            )

        # 這題沒有任何合法 skill，就完全不納入統計
        if not problem_skills:
            print(
                f"[跳過] {path} 沒有任何 JSON 中登記的 skill"
            )
            continue

        # 錯誤統計只計算至少含一個合法 skill 的題目
        for mistake in set(problem["mistakes"]):
            mistake_statistics[mistake] += 1

        # 同一題同一個 skill 只計算一次
        for skill in problem_skills:
            data = tag_statistics[skill]
            data["problem_count"] += 1

            all_scores_exist = all(
                problem[field] is not None
                for field in WEIGHTS
            )

            if all_scores_exist:
                data["evaluated_count"] += 1

            for field in WEIGHTS:
                score = problem[field]

                if score is not None:
                    data[field].append(score)

            for mistake in set(problem["mistakes"]):
                data["mistakes"][mistake] += 1

            problem_date = problem["date"]

            if problem_date is not None:
                if (
                    data["last_date"] is None
                    or problem_date > data["last_date"]
                ):
                    data["last_date"] = problem_date

    return tag_statistics, mistake_statistics


# =========================
# 熟練度計算
# =========================

def average(values: list[int]) -> float | None:
    if not values:
        return None

    return sum(values) / len(values)


def score_to_percentage(score: float | None) -> float:
    """
    將 1～5 分轉換成 0～100%。

    1 分 = 20%
    2 分 = 40%
    ...
    5 分 = 100%
    """

    if score is None:
        return 0.0

    return score / 5 * 100


def calculate_mastery(data: dict) -> float | None:
    """
    熟練度：

    Independent     30%
    Understanding   25%
    Implementation  25%
    Recognition     20%
    """

    averages = {
        field: average(data[field])
        for field in WEIGHTS
    }

    # 完全沒有任何評分資料
    if all(value is None for value in averages.values()):
        return None

    weighted_sum = 0.0
    available_weight = 0.0

    for field, weight in WEIGHTS.items():
        value = averages[field]

        if value is None:
            continue

        weighted_sum += score_to_percentage(value) * weight
        available_weight += weight

    if available_weight == 0:
        return None

    # 若有部分欄位缺失，只用現有欄位重新正規化
    return weighted_sum / available_weight


def get_mastery_level(score: float | None) -> str:
    if score is None:
        return "未評分"

    if score >= 90:
        return "精通"

    if score >= 75:
        return "熟練"

    if score >= 60:
        return "可使用"

    if score >= 40:
        return "學習中"

    return "薄弱"


def format_average(value: float | None) -> str:
    if value is None:
        return "-"

    return f"{value:.1f}/5"


# =========================
# Markdown 產生
# =========================

def build_tag_table(tag_statistics: dict) -> str:
    rows = []

    for tag, data in tag_statistics.items():
        mastery = calculate_mastery(data)

        most_common_mistakes = sorted(
            data["mistakes"].items(),
            key=lambda item: (-item[1], item[0]),
        )

        mistakes_text = ", ".join(
            f"{name}({count})"
            for name, count in most_common_mistakes[:3]
        )

        if not mistakes_text:
            mistakes_text = "-"

        rows.append(
            {
                "tag": tag,
                "problem_count": data["problem_count"],
                "evaluated_count": data["evaluated_count"],
                "independent": average(data["independent"]),
                "understanding": average(
                    data["understanding"]
                ),
                "implementation": average(
                    data["implementation"]
                ),
                "recognition": average(
                    data["recognition"]
                ),
                "mastery": mastery,
                "level": (
                    "尚未使用"
                    if data["problem_count"] == 0
                    else get_mastery_level(mastery)
                ),
                "mistakes": mistakes_text,
                "last_date": (
                    data["last_date"].isoformat()
                    if data["last_date"] is not None
                    else "-"
                ),
            }
        )

    # 排序規則：
    # 1. 完全沒有使用過的 skill 排最前面，提醒補題。
    # 2. 已使用的 skill 依熟練度由高到低排列。
    # 3. 熟練度相同時，題數較多的排前面。
    rows.sort(
        key=lambda row: (
            0 if row["problem_count"] == 0 else 1,
            -(
                row["mastery"]
                if row["mastery"] is not None
                else -1
            ),
            -row["problem_count"],
            row["tag"],
        )
    )

    lines = [
        "| 知識點 | 題數 | 已評分 | 獨立 | 理解 | 實作 | 辨識 | 熟練度 | 等級 | 常見錯誤 | 最近練習 |",
        "| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | --- | --- | --- |",
    ]

    for row in rows:
        mastery_text = (
            f"{row['mastery']:.1f}%"
            if row["mastery"] is not None
            else "-"
        )

        lines.append(
            f"| `{row['tag']}` "
            f"| {row['problem_count']} "
            f"| {row['evaluated_count']} "
            f"| {format_average(row['independent'])} "
            f"| {format_average(row['understanding'])} "
            f"| {format_average(row['implementation'])} "
            f"| {format_average(row['recognition'])} "
            f"| {mastery_text} "
            f"| {row['level']} "
            f"| {row['mistakes']} "
            f"| {row['last_date']} |"
        )

    return "\n".join(lines)


def build_mistake_table(mistake_statistics: dict) -> str:
    sorted_mistakes = sorted(
        mistake_statistics.items(),
        key=lambda item: (-item[1], item[0]),
    )

    lines = [
        "| 錯誤類型 | 次數 |",
        "| --- | ---: |",
    ]

    for mistake, count in sorted_mistakes:
        lines.append(f"| `{mistake}` | {count} |")

    if not sorted_mistakes:
        lines.append("| - | 0 |")

    return "\n".join(lines)


# =========================
# README 更新
# =========================

def replace_section(
    original: str,
    start_marker: str,
    end_marker: str,
    content: str,
) -> str:
    pattern = re.compile(
        rf"{re.escape(start_marker)}"
        rf".*?"
        rf"{re.escape(end_marker)}",
        flags=re.DOTALL,
    )

    if pattern.search(original) is None:
        raise ValueError(
            "README.md 找不到以下區段：\n"
            f"{start_marker}\n"
            f"{end_marker}"
        )

    replacement = (
        f"{start_marker}\n\n"
        f"{content}\n\n"
        f"{end_marker}"
    )

    return pattern.sub(
        lambda _: replacement,
        original,
    )


def update_readme(
    tag_table: str,
    mistake_table: str,
) -> bool:
    if not README_PATH.exists():
        raise FileNotFoundError(
            f"找不到 README：{README_PATH}"
        )

    original = README_PATH.read_text(encoding="utf-8")

    updated = replace_section(
        original,
        STATS_START,
        STATS_END,
        tag_table,
    )

    updated = replace_section(
        updated,
        MISTAKES_START,
        MISTAKES_END,
        mistake_table,
    )

    if updated == original:
        return False

    README_PATH.write_text(
        updated,
        encoding="utf-8",
    )

    return True


# =========================
# 主程式
# =========================

def main() -> None:
    tag_statistics, mistake_statistics = (
        collect_statistics()
    )

    tag_table = build_tag_table(tag_statistics)
    mistake_table = build_mistake_table(
        mistake_statistics
    )

    changed = update_readme(
        tag_table,
        mistake_table,
    )

    print(f"知識點數量：{len(tag_statistics)}")
    print(f"錯誤種類數量：{len(mistake_statistics)}")

    if changed:
        print("README.md 已更新")
    else:
        print("README.md 沒有變化")


if __name__ == "__main__":
    main()
