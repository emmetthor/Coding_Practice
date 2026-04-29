# 題目名稱

## 題目敘述

- [原題連結](https://atcoder.jp/contests/abc452/tasks/abc452_e)

## 提示

1. `mod` 好難算，可以轉成什麼形式比較好？
2. 若固定 $j$，$\lfloor \frac{i}{j} \rfloor$ 的值會如何變動？
3. $$\sum_{i=1}^{n} \frac{n}{i} \approx n \log n$$

- [原題解答](https://atcoder.jp/contests/abc452/editorial/18409)

## 思考流程

1. 看到 $i \bmod j$，可以轉成 $i - j \times \lfloor \frac{i}{j} \rfloor$ 比較好算。
2. $$\begin{aligned}\sum_{i=1}^{N} \sum_{j=1}^{M} A_i \cdot B_j \cdot (i \bmod j) &= \sum_{j=1}^{M} B_j \cdot (\sum_{i=1}^{N} A_i \cdot (i - j \times \lfloor \frac{i}{j} \rfloor)) \\ &= \sum_{j=1}^{M} B_j \cdot (\sum_{i=1}^{N} i \cdot A_i - j \sum_{i=1}^{N} A_i \cdot \lfloor \frac{i}{j} \rfloor)\end{aligned}$$
3. 如果固定 $j$ 去看 $\lfloor \frac{i}{j} \rfloor$，會發現值會是：

    ```txt
    i =   | 1   2   3   4   5   6   7   8   ...
    ----------------------------------------------
    j = 1 | 1   2   3   4   5   6   7   8   ...
    j = 2 | 0   1   1   2   2   3   3   4   ...
    j = 3 | 0   0   1   1   1   2   2   2   ...
    j = 4 | 0   0   0   1   1   1   1   2   ...
    ```

4. 發現隨著 $i$ 增加，$\lfloor \frac{i}{j} \rfloor$ 會成塊狀 (每 i 項一組) 變成 `[0, 0, ..., 0][1, 1, ..., 1][2, 2, ..., 2], ...` 的形式。

5. 如果暴力算這些塊，那時間複雜度會是：$$n + \frac{n}{2} + \frac{n}{3} + \cdots = \sum_{i=1}^{n} \frac{n}{i} \approx n \log n$$

6. 因此，可以欲處理：$\sum_{i=1}^{N} i \cdot A_i$ 和 $j \sum_{i=1}^{N} A_i \cdot \lfloor \frac{i}{j} \rfloor$就可以在總複雜度為 $O(n \log n)$ 算出答案。

## 實作方法

- [程式碼](https://github.com/emmetthor/Coding_Practice/blob/main/problems/ABC/452/E_You_WILL_Like_Sigma_Problem.cpp)

## Agent Prompt

> 請你扮演出題者，把本文預期的作法或是原題解答，詮釋給問題者。
