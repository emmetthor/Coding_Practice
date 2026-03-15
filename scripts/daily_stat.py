from pathlib import Path
from collections import defaultdict
import re
from datetime import datetime, timedelta

# ------------------------
# 讀題目檔案裡的日期
# ------------------------
problems_dir = Path("problems")
daily = defaultdict(int)

for cpp_file in problems_dir.rglob("*.cpp"):
    with open(cpp_file, "r", encoding="utf-8") as f:
        content = f.read()
        match = re.search(r"Date:\s*(\d{4}-\d{2}-\d{2})", content)
        if match:
            date = match.group(1)
            daily[date] += 1

# ------------------------
# 日期範圍
# ------------------------
DAYS = 90
today = datetime.today()
dates = [today - timedelta(days=i) for i in range(DAYS)]
dates.reverse()

# ------------------------
# SVG 參數
# ------------------------
square_size = 20
padding = 2
label_padding = 20
right_padding = 100  # 右側留給總題數
weeks = (DAYS + 6) // 7
height = 7 * (square_size + padding) + label_padding
width = weeks * (square_size + padding) + label_padding + right_padding

svg = f'<svg width="{width}" height="{height}" xmlns="http://www.w3.org/2000/svg">\n'

# 星期標籤
weekdays = ['Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat', 'Sun']
for i, wd in enumerate(weekdays):
    y = label_padding + i * (square_size + padding) + square_size / 2 + 4
    svg += f'  <text x="0" y="{y}" font-size="10" fill="black">{wd}</text>\n'

# 顏色映射
def get_color(n):
    if n == 0: return "#ebedf0"
    elif n == 1: return "#c6e48b"
    elif n == 2: return "#7bc96f"
    else: return "#196127"

# 畫格子 + hover tooltip
for idx, d in enumerate(dates):
    week_idx = idx // 7
    day_idx = d.weekday()
    x = label_padding + week_idx * (square_size + padding)
    y = label_padding + day_idx * (square_size + padding)
    day_str = d.strftime("%Y-%m-%d")
    count = daily.get(day_str, 0)
    color = get_color(count)
    svg += f'  <rect x="{x}" y="{y}" width="{square_size}" height="{square_size}" fill="{color}">\n'
    svg += f'    <title>{day_str}: {count} problem(s)</title>\n'
    svg += f'  </rect>\n'

# ------------------------
# 右側加總題數
# ------------------------
# 右側加總題數
total_count = sum(daily.values())
total_font_size = 16  # 原本 12 → 改大
svg += f'  <text x="{width - right_padding + 5}" y="{height/2}" font-size="{total_font_size}" fill="black">Total: {total_count}</text>\n'
svg += '</svg>'

# ------------------------
# 輸出
# ------------------------
Path("stats").mkdir(exist_ok=True)
with open("stats/heatmap.svg", "w", encoding="utf-8") as f:
    f.write(svg)

print("SVG heatmap with total count saved at stats/heatmap.svg")