# 等價類計數 Counting Equivalent States

## 核心知識點

把「**答案關心的特徵**」的特定性質 (通常為**個數**) 記錄下來，再分別對每一類**算貢獻**，加回答案裡。

---

## 介紹

### 等價類

[等價類](https://zh.wikipedia.org/zh-tw/%E7%AD%89%E4%BB%B7%E7%B1%BB)是數學上一個重要的觀念，對於原本的集合 $S$ 中，所有等價類 $A_i \subseteq S$ 中，必定滿足：

$$\bigcup_{i=1}^{n} A_i = S$$

$$\forall i \wedge \forall j \wedge i \not= j, A_i \cap A_j = \emptyset$$

### 計數

通常這類問題在計算貢獻時，會使用到**每一類的個數**。少數情況使用最大值、最小值等。

因此等價類計數問題**常常與[組合數](\Coding_Practice\techniques\math\combinatorics.md)有關**。

---

## 常見模型

### 找 key 等價

這類題目等價的性質會以 `pair` 或字串呈現， 因此可以使用 `unordered_map` 來記錄每一類的個數，最後貢獻答案。

### 前綴和等價

若遇到「**區間總和**」有關的等價類計數題目，通常會在 `prefix_sum` 中找等價類。

### 相差等價

若遇到「**出現個數**」有關的等價類計數題目，通常會在不同項目中，「**出現個數的差**」中找等價類。

### 同餘等價

若遇到與餘式定理、因數倍數、有關的等價類計數題目，通常需要先取餘，並以以同餘等價來做 counting。

---

## 常見錯誤

TODO

---

## 代表題目

| 題目 | 重點 |
| --- | --- |
| [ABC445E Unbalanced ABC Substrings](\Coding_Practice\problem_solutions\ABC\455\ABC455E.md) | 相差等價 |
| [LeetCode 2033 Minimum Operations to Make a Uni-Value Grid](\Coding_Practice\problem_solutions\LeetCode\LeetCode2033.md) | 同餘等價 |

---

## Agent Prompt

> 請你扮演這個知識點的老師，按照本文的介紹詮釋這個知識點。
> 若本文知識點有誤，請點出錯誤的地方並予以修正。
