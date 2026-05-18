# 中位數

## 核心知識點

**數列中正中間的數**。$\min \sum_{i=1}^{n} | a_i - x |$ 中的 $x$ 就是中位數。

---

## 介紹

中位數就是數列中正中間的數。若數列長為奇數，則 $A_{\frac{n + 1}{2}}$ 為中位數，反之則是 $\frac{A_{\frac{n}{2}} + A_{\frac{n}{2} + 1}}{2}$。

對於一維與二維曼哈頓距離，中位數其實就是 $\min \sum_{i=1}^{n} | a_i - x |$ 中的 $x$。

> **[證明]**
> **[Lemma]** 先考慮 $g(x) = |x - l| + |x - r|$。
> 對於所有 $l \le r$，試證明 $\min \arg g(x) \in [l, r]$。
> $x < l \Rightarrow g(x) = l - x + r - x = (l + r) - 2x$
> $x > r \Rightarrow g(x) = x - l + x - r = 2x - (l + r)$
> $l \le x \le r \Rightarrow g(x) = x - l + r - x = r - l$
> $r - l \ge (l + r) - 2x \wedge r - l \ge 2x - (l + r) \Rightarrow \min \arg g(x) \in [l, r] \#$
>
> **[Proof]** 回到原問題， $f(x) = \sum_{i=1}^{n} | a_i - x |$。
> 若我們有意識的把 $a_i$ 進行配對，配成 $(a_1, a_n), (a_2, a_{n-1}), \ldots$
> 透過 Lemma 可知每一組 $\min \arg |a_l - x| + |a_r - x|$ 的解都 $\in [a_l, a_r]$。
> 把所有組的解取交集，答案就會是最中間配對的那組答案，也就會是中位數。

---

## 常見題型

### 動態中位數

這可以使用兩種實作方式解決：

1. 用 `set<pair<int, int>>` 的指標紀錄中位數位置。
2. 用兩個 `multiset<int>` 分別記錄前半的數與後半的數。

### 最小化曼哈頓距離

這種題目可以直接套用中位數解題。
只要看到類似 $\sum_{i=1}^{n} |a_i - x|$ 的式子，所有的 $x$ 都會是中位數。

---

## 代表題目

| 題目 | 重點 |
| --- | --- |
| Atcoder Beginner Contest 458D Chalkboard Median | 動態中位數 |

---

## Agent Prompt

> 請你扮演這個知識點的老師，按照本文的介紹詮釋這個知識點。
> 若本文知識點有誤，請點出錯誤的地方並予以修正。
