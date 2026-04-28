# Combinatorics

## 介紹

組合數的概念是：從 n 個數中隨便取出 k 個，總共有幾種取法。可記為：

$$C_k^n = \binom{n}{k}$$

其公式可從排列推得：

> **[問題]**
> 什麼是排列？就是從 n 個相異物選 k 個東西排成一列，總共有幾種排法。
> 可使用空位排物法得知：
> $$P^n_k=n\times (n-1) \times \cdots \times (n-k+1) = \frac{n!}{(n-k)!}$$

$$
\binom{n}{k}=\frac{P^n_k}{k!}=\frac{\frac{n!}{(n-k)!}}{k!}=\frac{n!}{k!(n-k)!}
$$

## 巴斯卡三角形

如果 $\binom{n}{k}$ 中 n 與 k 都很小 ($\le 5000$)，可以直接暴力計算此三角形，直接求解。
一個巴斯卡三角形的 DP 定義如下：
> **[定義]**
> **`dp[i][j] := 從 i 個東西中取 j 個，總共有幾種取法`。**
> **`dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]`**。
> **[問題]**
> 為何可以這樣轉移？
> $$\begin{aligned}\binom{n}{k} = \frac{n!}{k!(n-k)!} &= \text{Choosing the last one} \times \text{Not choosing the last one}\\ &=\frac{(n-1)!}{(k-1)!(n-k)!} \times \frac{(n-1)!}{k!(n-k-1)!}\\\\ &= \binom{n - 1}{k - 1} \times \binom{n-1}{k}\end{aligned}$$
> 或是使用巴斯卡三角形的樣子想：
> $$\begin{array}{ccccccccc}
& & & & 1 & & & & \\
& & & 1 & & 1 & & & \\
& & 1 & & 2 & & 1 & & \\
& 1 & & 3 & & 3 & & 1 & \\
1 & & 4 & & 6 & & 4 & & 1
\end{array}$$
> 每一項都是上面相鄰兩項的和。

## 題目

| 題目 | 詳解 |
| - | - |
| [CSES Empty String](https://cses.fi/problemset/task/1080) | TODO |
