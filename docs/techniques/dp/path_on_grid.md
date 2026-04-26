# Path On Grid

## 介紹

若題目與二維地圖有關，而且**移動方向有限制**，就常常可以用這種 DP 解題。

> **[注意]**\
> 若移動方向是四向或八向，就需要使用最短路演算法。

## DP 狀態與轉移

### 一人走法

通常以 `dp[i][j] := 抵達 (i, j) 的答案` 當作狀態，~~十分直觀對吧~~。
但是轉移卻有兩種模式：

1. `dp[i][j]` 與**往回一步可以去的地方**有關。
2. `dp[i][j]` 與**所有走 k 步可以去的地方**有關。

這要根據題目去做對應變化。

### 兩人走法

若要同時維護兩人的走法，就要定義 `dp[step][r1][r2] := 走 step 步時，第一人在 (r1, step - r1) 且 第二人在 (r2, 2n - 2 - step - r2)` 的答案。

> **[注意]**\
> 有時記憶體不夠大時，就需要**將 `step` 壓縮**，轉為由 `dp` 與 `new_dp` 維護舊與新的 DP 狀態。

## 題目

| 題目 | 詳解 |
| - | - |
| [CSES Minimal Grid Path](https://cses.fi/problemset/result/16510901/) | TODO |
| [USACO GOLD Palindromic Paths](https://usaco.org/index.php?page=viewproblem2&cpid=553) | TODO |
