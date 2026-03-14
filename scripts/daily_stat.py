import subprocess
from datetime import datetime
from collections import defaultdict
import os
import matplotlib.pyplot as plt

# 取得 commit 日期
log = subprocess.check_output(
    ["git", "log", "--diff-filter=A", "--name-only", "--pretty=format:%ad", "--date=short", "--", "problems"]
).decode()

daily = defaultdict(int)

for line in log.splitlines():
    date = datetime.strptime(line, "%Y-%m-%d")
    key = date.strftime("%Y-%m-%d")
    daily[key] += 1

x = sorted(daily.keys())
y = [daily[d] for d in x]

plt.figure()
plt.plot(x, y, marker="o")
plt.xticks(rotation=60)
plt.xlabel("Date")
plt.ylabel("Solved Problems")
plt.title("Daily Practice")

os.makedirs("stats", exist_ok=True)
plt.tight_layout()
plt.savefig("stats/daily_solved.svg")