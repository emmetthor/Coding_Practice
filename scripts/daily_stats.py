from pathlib import Path
from collections import defaultdict
import re
from datetime import datetime, timedelta

# ------------------------
# 讀題目檔案裡的日期
# ------------------------
problems_dir = Path("docs/problems")
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

start_date = today - timedelta(days=DAYS - 1)
grid_start = start_date - timedelta(days=start_date.weekday())  # 對齊到星期一

dates = []
cur = grid_start
while cur <= today:
    dates.append(cur)
    cur += timedelta(days=1)

# ------------------------
# SVG 參數
# ------------------------
square_size = 20
padding = 2
label_padding = 28
right_padding = 120

weeks = (len(dates) + 6) // 7
height = 7 * (square_size + padding) + label_padding
width = weeks * (square_size + padding) + label_padding + right_padding

svg = f'<svg width="{width}" height="{height}" xmlns="http://www.w3.org/2000/svg">\n'

# 星期標籤
weekdays = ['Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat', 'Sun']
for i, wd in enumerate(weekdays):
    y = label_padding + i * (square_size + padding) + square_size / 2 + 4
    svg += f'  <text x="0" y="{y}" font-size="12" fill="white">{wd}</text>\n'

# 顏色映射
def get_color(n):
    if n == 0:
        return "#1D2320"
    elif n == 1:
        return "#223400"
    elif n == 2:
        return "#13490b"
    elif n == 3:
        return "#116522"
    elif n == 4:
        return "#1C9434"
    elif n <= 5:
        return "#3BCB58"
    elif n <= 6:
        return "#46CA63"
    elif n <= 7:
        return "#61CD7F"
    elif n <= 8:
        return "#8CD2A0"
    elif n <= 9:
        return "#B5DFC0"
    else:
        return "#FFFFFF"

def get_text_color(n):
    if n >= 9:
        return "#000000"  # 淺色格子用黑字
    else:
        return "white"    # 深色格子用白字

# 畫格子
for d in dates:
    week_idx = (d - grid_start).days // 7
    day_idx = d.weekday()  # Mon=0 ... Sun=6

    x = label_padding + week_idx * (square_size + padding)
    y = label_padding + day_idx * (square_size + padding)

    day_str = d.strftime("%Y-%m-%d")
    count = daily.get(day_str, 0)
    color = get_color(count)
    text_color = get_text_color(count)

    svg += f'  <rect x="{x}" y="{y}" width="{square_size}" height="{square_size}" fill="{color}">\n'
    svg += f'    <title>{day_str}: {count} problem(s)</title>\n'
    svg += f'  </rect>\n'

    # 在方框中央標題數
    if count != 0: 
        svg += (
            f'  <text x="{x + square_size / 2}" '
            f'y="{y + square_size / 2 + 1}" '
            f'font-size="10" '
            f'fill="{text_color}" '
            f'text-anchor="middle" '
            f'dominant-baseline="middle" '
            f'pointer-events="none">{count}</text>\n'
        )

# 總題數
total_count = sum(daily.values())
svg += f'  <text x="{width - right_padding + 5}" y="{height/2}" font-size="18" fill="white">Total: {total_count}</text>\n'

svg += '</svg>'

# ------------------------
# 輸出
# ------------------------
Path("docs").mkdir(exist_ok=True)
with open("docs/public/heatmap.svg", "w", encoding="utf-8") as f:
    f.write(svg)

print("SVG heatmap saved at docs/public/heatmap.svg")
