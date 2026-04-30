# 數學式化簡

## 核心知識點

把數學式轉「**可預先處理、可維護、可分開算**」的形式。

---

## 常見模型

### 所有不重複 pair 的乘積

$$
\sum_{i = 1}^{n} \sum_{j = i + 1}^{n} A_i A_j = \frac{(\sum_{i = 1}^{n} A_i)^2 - \sum_{i = 1}^{n} A_i ^ 2}{2}
$$

證明：

不失一般性，考慮 $A = [A_1, A_2, A_3, A_4]$，若把所有 (可重複) pair 的乘積寫下來，那會是：

```cpp
A_1 * A_1, A_1 * A_2, A_1 * A_3, A_1 * A_4
A_2 * A_1, A_2 * A_2, A_2 * A_3, A_2 * A_4
A_3 * A_1, A_3 * A_2, A_3 * A_3, A_3 * A_4
A_4 * A_1, A_4 * A_2, A_4 * A_3, A_4 * A_4
```

則可以先去掉所有平方項 $A_i^2$，再因為 $A_iA_j = A_jA_i$，把剩下的 $\div 2$ 就是答案。

### 同類項合併

若遇到需要枚舉 $i \in [1, n], j \in [1, n]$ 的題型，通常可以藉由把**公式中的「`i` 與 `i` 項並一起， `j` 與 `j` 項並一起」**來把 $O(n^2)$ 枚舉降至 $O(n)$。

### 餘式定理轉取餘

通常與餘式定理與同餘相關的問題都可以轉成取餘的形式。詳細請見[取餘](\Coding_Practice\techniques\math\modulo)。

### 取餘轉公式

通常取餘可以轉成 $i \mod j = i - \lfloor \frac{i}{j} \rfloor$。詳細請見[取餘](\Coding_Practice\techniques\math\modulo.md)。

### 操作轉排列組合

有些複雜的數學公式可以轉成組合數的形式。詳細請見[組合數](\Coding_Practice\techniques\math\combinatorics)。

---

## 常見錯誤

TODO

---

## 代表題目

| 題目 | 重點 |
| --- | --- |
| [ABC452E You WILL Like Sigma Problem](\Coding_Practice\problem_solutions\ABC\452\ABC452E) | 取餘轉公式 + $\sum$ |

---

## Agent Prompt

> 請你扮演這個知識點的老師，按照本文的介紹詮釋這個知識點。
> 若本文知識點有誤，請點出錯誤的地方並予以修正。
