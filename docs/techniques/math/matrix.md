### 矩陣快速冪

#### 矩陣乘法

$$
\begin{bmatrix}
a & b
\end{bmatrix} \times
\begin{bmatrix}
p & q \\ r & s
\end{bmatrix} =
\begin{bmatrix}
a \times p + b \times r & a \times q + b \times s
\end{bmatrix}
$$

#### 快速冪矩陣推導

要推導出該使用的矩陣，先把輸入與輸出寫下來。以費波納契數列舉例：

$$
input:
\begin{bmatrix}
F_{n-1} & F_{n-2}
\end{bmatrix} \quad
output:
\begin{bmatrix}
F_n & F_{n-1}
\end{bmatrix}
$$

接著列出遞迴式：
$$
F_n = 
\begin{cases}
1 & \text{if } n = 1 \vee 2\\
F_{n-1} + F_{n-2} & \text{if } n \in \mathbb{N} \wedge n > 2
\end{cases}
$$

最後用矩陣乘法一一對應需要的項目，即可推出：

$$
v_n=
\begin{bmatrix}
F_n & F_{n-1}
\end{bmatrix}=
\begin{cases}
\begin{bmatrix}
1 & 1
\end{bmatrix} & \text{if } n = 2\\
\begin{bmatrix}
F_{n-1} &  F_{n-2}
\end{bmatrix} \times
\begin{bmatrix}
1 & 1\\
1 & 0
\end{bmatrix}
& \text{if } n \in \mathbb{N} \wedge n > 2\\
\end{cases}
$$

因此計算的快速冪就是：
$$
\begin{bmatrix}
F_n & F_{n-1}
\end{bmatrix}=
\begin{bmatrix}
F_1 &  F_2
\end{bmatrix} \times
\begin{bmatrix}
1 & 1\\
1 & 0
\end{bmatrix}^{n - 1}
$$

#### dp 形式的矩陣

如果 dp 題需要矩陣優化，通常 **dp 會和固定的前幾項有關**，如果不固定就無法寫成矩陣了。

#### 圖論形式的矩陣

如果圖論需要矩陣優化，通常的轉移矩陣定義方式為：

$$
\begin{bmatrix}
dis(v_1, v_1) & dis(v_1, v_2) & \cdots & dis(v_1, v_n) \\
dis(v_2, v_1) & dis(v_2, v_2) & \cdots & dis(v_2, v_n) \\
\vdots & \vdots & \ddots & \vdots \\
dis(v_n, v_1) & dis(v_n, v_2) & \cdots & dis(v_n, v_n)
\end{bmatrix}
$$

並將矩陣乘法變為轉移式，就可以用矩陣快速冪優化。