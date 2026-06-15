# 二分搜 Binary Search

## 核心知識點

有單調性並要求極值，就可以設定上下界 $O(\log n)$ 快速搜出答案。

---

## 介紹

二分搜的前提是**單調性**的存在。

### 單調性

在程式中，單調性可以有兩種形式。

1. 數學單調性。也就是**一函數遞增或遞減**。
2. 存在 `false, false, ..., false, true, true, ..., true`，可以明確給定搜索方向的序列。（也就是遇到 `false` 就往右找，遇到 `true` 就往左找。）

---

## 實作

### 整數二分搜

```cpp
int low = 0, hi = MAX;
while (low <= hi)
{
    int mid = (low + hi) / 2;
    if (f(mid) == true)
        low = mid + 1;
    else
        hi = mid - 1;
}

cout << low;
```

### 浮點數二分搜

由於浮點數精度不需太高，因此可以只跑六十次，直接暴力算出中位數。

```cpp
double low = 0, hi = MAX;
for (int t = 0; t < 60; t++)
{
    double mid = (low + hi) / 2;
    if (f(mid) == true)
        low = mid;
    else
        hi = mid;
}

cout << low;
```

---

## 常見模型

### lower_bound / upper_bound 應用

請見 [lower_bound 與 upper_bound](../binary_search/lower_bound_and_upper_bound.md)。

### 最大化最小值 / 最小化最大值

只要看到題目出現「最大化最小值 / 最小化最大值」等字眼，第一步通常都是直接二分搜答案。

> **[證明]** 最大化最小值 / 最小化最大值 一定可以二分搜
> 不失一般性，最大化最小值為例。
> 如果假設答案為 $a$，則若以答案為 $x$ 驗證合法性時，會發現所有 $x \ge a$ 的情況，這個 $x$ 都必定能達成；反之 $x < a$ 則不可能達成。
> 這個特性正好符合第二種單調性：`false, false, ..., false, true, true, ..., true`，因此可以二分搜。

### 第 k 小 / 大

若把二分搜搜尋的項目改成：

> 猜測東西是 $x$，有幾個東西會 $\le x$ 呢？

如果 $\le x$ 的數量至少有 $k$ 個，代表第 $k$ 小必定 $\le x$。這便可以二分搜。

(### 門檻二分搜)

### 中位數二分搜

若要搜尋中位數 $x$，可以把序列轉換成：
$$
a_i =
\begin{cases}
+1 & \text{if } a_i \ge x\\
-1 & \text{if } a_i < x
\end{cases}
$$
則若有某區間總和 $\ge 0$，就代表 $\ge x$ 的數字個數至少有一半以上，則中位數也就必須 $\le x$。

### 三分搜



---

## 常見錯誤

- **未確認適當的最小值與最大值**，導致計算時出現非法的數值。
- 計算 `mid` 時未注意可能有負數出現。應使用 `low + (hi - low) / 2`。
- 計算 `mid` 時 `integer overflow`。

---

## 代表題目

| 題目 | 重點 |
| --- | --- |
| CSES Array Division | 剛好 k 塊 = 至多 k 塊 |

---

## Agent Prompt

> 請你扮演這個知識點的老師，按照本文的介紹詮釋這個知識點。
> 若本文知識點有誤，請點出錯誤的地方並予以修正。
