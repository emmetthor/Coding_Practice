# Range DP

## 介紹

區間 DP 是特化 DP 狀態為 `dp[l][r] := 在區間 [l, r] 中的答案` 的特殊題目，根據轉移的不同可以分為兩種：

| DP 模式 | 解釋 | 時間複雜度 |
| - | - | - |
| 2D0D | 不需要額外枚舉的區間 DP | $O(n^2)$ |
| 2D1D | 需要 `for (i = l ~ r)` 轉移的 DP | $O(n^3)$ |

## 題目

| 題目 | 詳解 |
| - | - |
| [CSES Empty String](https://cses.fi/problemset/task/1080/) | TODO |
