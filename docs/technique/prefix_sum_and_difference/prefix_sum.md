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
