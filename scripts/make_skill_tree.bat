@echo off

dot -Tsvg stats/skill_tree.dot -o docs/img/skill_tree.svg

echo skill_tree.svg generated at docs/img using stats/skill_tree.dot 