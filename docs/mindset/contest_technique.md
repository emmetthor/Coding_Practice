# 競賽策略 Contest Technique

## 這個 skill 解決什麼問題？

實際競賽時，出現以下問題：

1. **未抓出簡單題**予以實作。
2. **未抓出次簡單題**，多給予時間思考與實作。
3. **卡在同一題過久**，以至於沒有時間解其他題目。
4. **抓錯過久**，以至於根本沒發現想法就是錯的。

## 使用時機

實體或虛擬競賽時。

## 核心想法

以西洋棋引擎的搜尋模式解題。先標記難易度，再分別調整所需時間，記得注意時間是否過久，並快速跳題。

## 思考流程

```mermaid
graph LR

st["開始比賽"]

scan["瀏覽所有題目，大致標記難易度 (aspiration window?)"]

read["開始讀題，中等以下題 10min 難題 15min"]

solve_easy["在 15 分鐘內解簡單題"]
solve_medium["在 20 分鐘內解中等題"]
solve_hard["在 30 分鐘內解難題"]
solve_easy_partial["在 10 分鐘內解部分分"]

st --> scan --> read

read -- "簡單題有解法" --> solve_easy --> read
read -- "中等題有解法" --> solve_medium --> read
read -- "(難題有解法)" --> solve_hard --> read
read -- "可以快速實作的部分分" --> solve_easy_partial --> read
```

## Agent Prompt

> 請你扮演這個 skill 的教練，按照本文的思考流程分析一場競賽的策略是否需要改進。
