import os
import re
from collections import defaultdict

tag_count = defaultdict(int)

for root, dirs, files in os.walk("problems"):
    for file in files:
        if file.endswith(".cpp"):
            path = os.path.join(root, file)

            with open(path, encoding="utf-8") as f:
                text = f.read()

            match = re.search(r"Tags:\s*(.*)", text)
            if match:
                tags = match.group(1).split(",")

                for t in tags:
                    tag_count[t.strip()] += 1

start = "<!-- STATS_START -->"
end = "<!-- STATS_END -->"

with open("README.md", encoding="utf-8") as f:
    readme = f.read()

stats = "\n| 題型 | 次數 |\n| - | - |\n" + "\n".join(f"| {k} | {v} |" for k,v in sorted(tag_count.items()))

new = re.sub(
    f"{start}.*?{end}",
    f"{start}\n{stats}\n{end}",
    readme,
    flags=re.S
)

with open("README.md","w",encoding="utf-8") as f:
    f.write(new)