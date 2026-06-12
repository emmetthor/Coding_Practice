# Weighted Interval Scheduling dp 加權區間排程 dp

## 這個 skill 解決什麼問題？

有權重的區間排程問題。

## 使用時機

有權重的區間排程問題。

## 核心想法

將區間的**權重設為報酬 + 取消損失**，最後再扣掉取消損失總和。

## 思考流程

1. 面對此種問題，可以先把區間以 `r` 排序，並想到 `dp[i][j] := 第 i 個事件選或不選，最多可以賺多少`。

2. 轉移式可以寫成：$$\begin{cases}dp[i][0] = \max\{dp[i- 1][0], dp[i - 1][1]\} - cancel\_loss \\dp[i][1] = \max\{dp[x][0], dp[x][1]\} + earn - \sum cancelled\_range\_loss\end{cases}$$，這裡的 x 是指最後一個不會被覆蓋的區間編號。

3. 但是，這個轉移式過於複雜，尤其是 $cancelled\_range\_loss$ 難以計算。

4. 因此，如果可以直接定義每個區間的權重，就很好計算了。
5. **注意到**，只有被選取的區間才不會被扣掉 $cancel\_loss$，因此可以先計算 $\sum cancel\_loss$，把區間權重改成 $earn + cancel\_loss$，這樣當選取區間之後，答案扣掉 $\sum cancel\_loss$ 就完成了！

## 常見模型

等待題目...

## 常見錯誤

等待題目...

## 代表題目

| 題目 | 重點 |
| --- | --- |
| AWC0090D Event Venue Reservation | 最典型的題型 |

## Agent Prompt

> 請你扮演這個 skill 的教練，按照本文的思考流程分析題目。
