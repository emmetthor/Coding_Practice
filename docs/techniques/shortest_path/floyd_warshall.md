# Floyd Warshll

## 介紹

Floyd Warshall 演算法可以 $O(n^3)$ 求出**所有點對的最短路**，可延伸至**最小環問題**。

### DP 證明

考慮一個 `dp[k][i][j] := 只能經過 點1 ~ 點k，從 i 到 j 的最短路是多長`，則其轉移式為：

$$
dp[k][i][j] = \min
\begin{cases}
dp[k - 1][i][k] + dp[k - 1][k][j] & \text{if pass k}\\
dp[k - 1][i][j] & \text{if not pass}
\end{cases}
$$

可以發現，其實 `dp[k]` 可以省略，因為每次計算時都可以直接取新的資料來覆蓋，因而產生 Floyd Warshall。

---

### 實作

```cpp
for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
    }
}
```

> **[注意]**
>
> 1. 變數 `k` 必須先枚舉，因為未壓縮前的 DP 定義就是如此！
> 2. 請在建立 `dis[][]` 時先**初始化所有 `dis[i][i] = 0`**。
