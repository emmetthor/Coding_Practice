# Difference

## 介紹

差分是一種**快速處理區間修改**的技巧，與前綴和互為逆運算。

### 基本定義

一個**差分序列**的每一項為：

$$
d[i] = a[i] - a[i - 1]
$$

差分序列紀錄的是**數據的變化量**，因此若要對區間 $[l, r]$ 每一項 $+1$，則只需更改：

$$
d[l] = d[l] + 1\\
d[r + 1] = d[r + 1] - 1
$$

可以用這張圖片理解：

![差分](https://pic3.zhimg.com/v2-cec2bca879de5627d79d2095acf3c842_r.jpg)

### 特殊用法

由每一項的定義 $d[i] = a[i] - a[i - 1]$ 可以推廣成函數，若要求出 $x = k$ 時的答案 $ans$，則可以定義函數 $f(x)$ 為前 $x$ 項 $ans$ 的和，就可以用 $f(x) - f(x - 1) = ans$ 求出答案。

## 題目

| 題目 | 詳解 |
| - | - |
| [ABC452F Interval Inversion Count](https://atcoder.jp/contests/abc452/tasks/abc452_f) | TODO |
