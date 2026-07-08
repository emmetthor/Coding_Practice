# Hexagonal Grid 六邊形網格

## 這個 skill 解決什麼問題？

六邊形網格。

## 使用時機

六邊形網格。

## 核心想法

將六邊形看成是立方體階梯的二維投影，再根據 $x + y + z = 0$ 轉換成 Axial 座標系。

## 介紹

六邊形網格題目的重點在於座標的呈現，而透過立方體階梯的二維投影與 $x + y + z = 0$ 性質，就可以用 $(q, r)$ 表示六邊形網格中的座標。

### 立方體階梯的二維投影

請上 [Hexagonal Grids](https://www.redblobgames.com/grids/hexagons/) 自行嘗試。

### Axial 座標系

由於 $x + y + z = 0$，因此儲存時不須要真正存 $(x, y, z)$，畢竟 $y = -(x + z)$，因此，在紀錄時，可以只記錄 $(x, z) = (q, r)$。

## 常見模型

### 網格上移動

從 $(x, y, z)$ 可推得，六角網格上的移動會是：

$$
\begin{array}{ccc}
x & y & z\\
\hline
+1 & 0 & -1 \\
\hline
+1 & -1 & 0 \\
\hline
0 & +1 & -1 \\
\hline
0 & -1 & +1 \\
\hline
-1 & 0 & +1 \\
\hline
-1 & +1 & 0 \\
\end{array}
$$

轉換成 Axial 就是：

$$
\begin{array}{cc}
x & z\\
\hline
+1 & -1 \\
\hline
+1 &  0 \\
\hline
0 &  -1 \\
\hline
0 &  +1 \\
\hline
-1 & +1 \\
\hline
-1 &  0 \\
\end{array}
$$

### 順時針 / 逆時針旋轉

藉由 $(x, y, z)$ 網格圖可以看出，

順時針旋轉是：

$$(x, y, z) \rightarrow (-y, -z, -x)$$

逆時針旋轉是：

$$(x, y, z) \rightarrow (-z, -x, -y)$$

轉換成 Axial 的順時針旋轉就是：

$$(-y, -x) = (x + z, -x)$$

轉換成 Axial 的逆時針旋轉就是：

$$(-z, -y) = (-z, x + z)$$

## 常見錯誤

TODO

## 代表題目

| 題目 | 重點 |
| --- | --- |

## Agent Prompt

> 請你扮演這個 skill 的教練，按照本文的思考流程分析題目。
