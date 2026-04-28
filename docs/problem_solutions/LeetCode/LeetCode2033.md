# 2033. Minimum Operations to Make a Uni-Value Grid

## 題目敘述

- [原題連結](https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/description/)

## 提示

1. 該如何確定一個 `grid` 必定有解？
2. 可用取餘確定有解。
3. 該選 `grid` 中的哪個數當作最小值？
4. 如果把 `grid` 排序會如何？

- [原題解答](https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/editorial)

## 思考流程

1. 發現所有在 `grid` 的數 $A_i$ 都必須滿足 $\forall i, A_i + k \times x$ 都相同。
2. 可以轉成把 $\forall i, A_i$ 皆取 $\mod x$，如果餘數相同，就必定有解。
3. 確定有解後，就可以選擇 `grid` 中的中位數當作要變相同的值。
4. 最後排序找中位數計算答案即可。

## 實作方法

- [程式碼](https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/submissions/1989829513)

## Agent Prompt

> 請你扮演出題者，把本文預期的作法或是原題解答，詮釋給問題者。
