import subprocess
from collections import defaultdict
from datetime import datetime
import matplotlib.pyplot as plt
import os

# 取得 git log
log = subprocess.check_output(
    [
        "git",
        "log",
        "--diff-filter=A",
        "--name-only",
        "--pretty=format:%ad",
        "--date=short",
        "--",
        "problems"
    ]
).decode()

daily = defaultdict(int)
current_date = None

for line in log.splitlines():
    line = line.strip()

    # 日期行
    if line.startswith("20"):
        current_date = line

    # 新增題目檔案
    elif line.endswith(".cpp"):
        daily[current_date] += 1


# 排序
dates = sorted(daily.keys())
counts = [daily[d] for d in dates]


# 只顯示最近 30 天
N = 30
dates = dates[-N:]
counts = counts[-N:]


# 畫圖
plt.figure(figsize=(8,4))
plt.plot(dates, counts, marker="o")

plt.xticks(rotation=45)
plt.xlabel("Date")
plt.ylabel("Solved Problems")
plt.title("Daily Solved Problems")

plt.tight_layout()

# 存成 SVG
os.makedirs("stats", exist_ok=True)
plt.savefig("stats/daily_solved.svg")