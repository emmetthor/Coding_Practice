# 動態中位數

## 核心知識點

用 `set<pair<int, int>>` 指標或兩個 `multiset` 分別維護中位數前與中位數後的數。

---

## 介紹

中位數就是數列中正中間的數。若數列長為奇數，則 $A_{\frac{n + 1}{2}}$ 為中位數，反之則是 $\frac{A_{\frac{n}{2}} + A_{\frac{n}{2} + 1}}{2}$。

---

### 實作方式

#### `set<pair<int, int>>` 紀錄數字與編號

#### 兩個 `multiset<int>` 紀錄前半與後半

---

## 代表題目

| 題目 | 重點 |
| --- | --- |
| Atcoder Beginner Contest 458D Chalkboard_Median | 動態中位數 |

---

## Agent Prompt

> 請你扮演這個知識點的老師，按照本文的介紹詮釋這個知識點。
> 若本文知識點有誤，請點出錯誤的地方並予以修正。
