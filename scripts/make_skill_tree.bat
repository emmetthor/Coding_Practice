@echo off

dot -Tsvg stats/skill_tree.dot -o docs/public/skill_tree.svg

echo skill_tree.svg generated at docs/public using stats/skill_tree.dot 