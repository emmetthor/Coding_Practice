# 題目名稱

## 題目敘述

- [原題連結](https://atcoder.jp/contests/abc455/tasks/abc455_e)

## 提示

1. 請使用**排容原理**。
2. 一個子字串中的 $n(A) - n(B), n(B) - n(C), n(C) - n(A)$ 與其他子字串的配對有關。
3. 若兩字串中的 $n(A) - n(B), n(B) - n(C), n(C) - n(A)$ 相同，這代表什麼？
4. [原題解答](https://atcoder.jp/contests/abc455/editorial/19452)

## 思考流程

1. 若要求出所有字母出現次數不同的子字串個數，可以轉換成 **全部的子字串數量 - 有字母出現次數相同的子字串個數**。
2. 有字母出現次數相同的子字串個數可用排容原理得出其個數為：$n(A_{cnt} = B_{cnt}) + n(B_{cnt} = C_{cnt}) + n(C_{cnt} = A_{cnt}) - 3 \times n(A_{cnt} = B_{cnt} = C_{cnt}) + n(A_{cnt} = B_{cnt} = C_{cnt})$。此推論可見下圖。
3. 不失一般性，若要求出 $n(A_{cnt} = B_{cnt} = C_{cnt})$，可以先用前綴和 $A, B, C$ 求出子字串中的字母個數。
4. 若子字串中的 $A_r - A_l = B_r - B_l = C_r - C_l$，其實可以轉換成：$(A_r - B_r, A_r - C_r) = (A_l - B_l, A_l - C_l)$ (請見 [數學式化簡](../../../techniques/math/equation_optimize.md))。
5. 而 $(A_r - B_r, A_r - C_r) = (A_l - B_l, A_l - C_l)$ 其實可以透過 [等價類計數](../../../techniques/math/counting_equivalent_states.md) 來計數，並貢獻答案為 $\binom{cnt}{2}$。
6. 因此，計算出所有需要計算的個數後，就可以輸出答案。

## 實作方法

[程式碼](../../../../problems/ABC/455/E_Unbalanced_ABC_Substrings.cpp)

## Agent Prompt

> 請你扮演出題者，把本文預期的作法或是原題解答，詮釋給問題者。
