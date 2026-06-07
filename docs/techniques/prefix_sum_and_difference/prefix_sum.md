# Prefix Sum

## 介紹

前綴和是一種**快速計算區間某性質**的技巧，與差分互為逆運算。

### 一維前綴和

一維前綴和的每項公式為：
$$
pre[i] = \sum_{i=1}^{n} a[i] = pre[i - 1] + a[i]
$$

若要求出區間 $[l, r]$ 的總和，則答案為：

$$
ans = pre[r] - pre[l - 1]
$$

### 二維前綴和

二維前綴和的每項公式為：

$$
pre[i][j] = \sum_{i=1}^{n} \sum_{j=1}^{m} a[i][j] = a[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1]
$$

若要求出長方形 $(x_1, y_1), (x_2, y_2)$ 的總和，則答案為：

$$
ans = pre[x_2][y_2] - pre[x_1 - 1][y_2] - pre[x_2][y_1 - 1] + pre[x_1 - 1][y_1 - 1]
$$

### 前綴 XOR

由於 XOR 操作具有以下性質：

$$
a \oplus a = 0\\
(a \oplus b) \oplus c = a \oplus (b \oplus c) = a \oplus b \oplus c
$$

因此若對 XOR 做前綴和，則會如以下形式：

$$
prefix[i] = prefix[i - 1] \oplus a[i]\\
$$

若要求出區間 $[l, r]$ 的 XOR 結果，則答案為：

$$
ans = prefix[r] \oplus prefix[l - 1]
$$

## 常見題型

### 連續區間和

當題目想要快速求**共有幾個連續區間和 = k**，可以轉換一維前綴和的數學式：

$$
\begin{aligned}
prefix[r] - prefix[l - 1] &= k \\
prefix[r] - k &= prefix[l - 1]
\end{aligned}$$

就可以紀錄 $prefix[l - 1]$ 的出現次數，直接做答案貢獻。

```c++
unordered_map<int, int> cnt;
int prefix = 0;
cnt[0]++;

for (int i = 0; i < n; i++)
{
    prefix += a[i];
    ans += cnt[prefix - k];
    cnt[prefix]++;
}
```

### 二維前綴和壓縮

當題目想要快速求**共有幾個矩形的和 = k**，由於二維前綴和無法快速求，因此要**固定上下界**，轉化為**一維前綴和**才能做**連續區間和**。

## 題目

| 題目 | 詳解 |
| - | - |
| [ABC461D Count Subgrid Sum = K](https://atcoder.jp/contests/abc461/tasks/abc461_d) | 二維前綴和壓縮 |
