# Binary Indexed Tree / Fenwick Tree / 樹狀陣列

## 這個 skill 解決什麼問題？

可用線段樹解決的**前綴問題**。

## 使用時機

區間總和，區間不同值個數。

## 介紹

樹狀陣列是經過極致優化的線段樹，其每個區間的範圍如下圖：

![BIT區間](https://hackmd.io/_uploads/SJnMXQLt6.png)

可以發現，其實每個區間可以從編號推出，以 $12$ 為例。

$12 = 01100_{(2)}$，而這個區間的長度是：$12$ 中最小的 1-bit 所貢獻的數，也就是 $4$。而區間結尾就是區間編號。

因此，BIT 中的 $x$ 號區間可以寫成：$[x - lowbit(x), x]$。

也因此，想要查詢 $1 \sim x$ 的區間答案，可以看成：

$$
\sum \text{interval of }
\langle a_i \rangle =
\begin{cases}
x & \text{if } i = 0\\
a_{i - 1} - lowbit(a_{i - 1}) & \text{if } i > 0 \wedge a_{i - 1} \ge 1
\end{cases}
$$

更因此，想要修改 $x$ 這項的值，可以看成將所有

$$
\langle a_i \rangle =
\begin{cases}
x & \text{if } i = 0\\
a_{i - 1} + lowbit(a_{i - 1}) & \text{if } i > 0 \wedge a_{i - 1} \le n
\end{cases}
$$

模板如下：

```c++
struct BIT
{
    int n;
    vector<int> a;

    BIT (int _n) : n(_n), a(_n + 1) {};

    void add(int x, int v)
    {
        for (int i = x; i <= n; i += i & -i)
        {
            a[i] += v;
        }
    }

    int prefix(int x)
    {
        int res = 0;
        for (int i = x; i >= 1; i -= i & -i)
        {
            res += a[i];
        }
        return res;
    }
};
```

## 常見模型

### 取得區間 [l, r]

由於 BIT 只能求出前綴和，因此要用錢綴和查詢的想法，將 $[l, r] = prefix(r) - prefix(l - 1)$。

因此因此模板可加上：

```c++
int sum(int l, int r)
{
    return prefix(r) - prefix(l - 1);
}
```

### 設定某值為 k

由於 BIT 只能修改，不能直接設定，因此要把設定成 k 想成：

**「修改原本的 $a[i]$，使其加上 $-a[i] + k$」**。

因此模板可加上：

```c++
void set(int x, int v)
{
    int ori = sum(x, x); // 取得區間 [x, x] 的答案
    add(x, -ori + v);
}
```

### 區間值種類查詢

TODO

## 常見錯誤

TODO

## 代表題目

| 題目 | 重點 |
| --- | --- |
| [CSES1648 Dynamic Range Sum Queries](https://cses.fi/problemset/task/1648/) | 裸 BIT |
| [CSES1734 Distinct Values Queries](https://cses.fi/problemset/task/1734/) | 區間值種類查詢 |

## Agent Prompt

> 請你扮演這個 skill 的教練，按照本文的思考流程分析題目。
