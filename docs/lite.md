# 程式模板庫 \& 考前速讀

## 讀題

1. 請仔細看變數範圍，有時可以猜出預期時間複雜度。

| n | 時間複雜度 | 可能的演算法 |
| - | - | - |
| $13$ | $O(n!)$ | 全排列枚舉 |
| $20$ | $O(2^n)$ | 二元枚舉 |
| $40$ | $O(2^\frac{n}{2})$ | 折半枚舉 |
| $150$ | $O(n^3 \log  n)$ | $n \times Dijkstra$ |
| $300 \sim 500$ | $O(n^3)$ | $Floyd-Warshall$ |
| $5000$ | $O(n^2)$ | |
| $10^5$ | $O(n \log n)$ | 二分搜 + 貪心、$Dijkstra$、資料結構、枚舉 $1 \sim n$ 倍數 |
| $10^6$ | $O(n) \vee O(n \sqrt n)$ | 貪心、dp、質數、**常數不大** |
| $10^8$ | $\Theta(10^8)$ | 暴力 |
| $\ge 10^{10}$ | $O(\log n)$ | 打表，矩陣快速冪 |

2. 請先排出題目難易度，並且**有意識的分配更多時間給簡單題**。
3. 可透過變數範圍猜猜時間複雜度。請將**暴力為 $O(10^8)$ 視為可行的**。
4. 將**可能的模型畫成樹，一一去想**。
5. 每題寫上：
```
題目轉換： 這裡寫將題目轉成數學的表達。
詢問：題目要求什麼。
特殊變數限制：奇怪的變數限制與猜測 O(?)。
```


## debug 表

### WA

1. $integer\ overflow$。
2. 不該 `sort` 的時候 `sort`。


### TLE

1. 在迴圈內建立陣列。
2. 使用複雜度較小的資料結構，如 $set \rightarrow pq$，$SegTree \rightarrow BIT$。

## 猜題

| 關鍵字 | 技巧 | 可能延伸 |
| -------- | -------- | -------- |
| $10^9$ 的 dp | 矩陣快速冪 | |
| 配對 - 可被單調化 | **循環配對** |  小心不能有**配對條件不對稱**的問題。|
| 二維地圖 - 單方向移動 | **二維地圖 dp** | 傳送 |
| 二維地圖 - 多方向移動 | **圖論** | 最短路、傳送 |
| 交換 | 分治， $BIT$ | |

### 簡單路徑

| 關鍵字 | 技巧 | 可能延伸 |
| -------- | -------- | -------- |
| 計算所有路徑 | **樹 dp** | 連通塊、樹直徑 |
| 多詢問路徑距離 | $\text{LCA}$ | 動態樹 dp |

### 可重複節點路徑

| 關鍵字 | 技巧 | 可能延伸 |
| -------- | -------- | -------- |
| 兩點查詢 | **倍增** | |
| 路徑長恰 $k$ 滿足條件 $XXX$ | **圖論 dp** | 矩陣快速冪 | 

### 區間詢問

| 關鍵字 | 技巧 | 可能延伸 |
| -------- | -------- | -------- |
| 靜態查詢表 | **倍增**$Sparse\ Table$ | |
| 前綴最大值 | $BIT$ | dp |
| **區間不同值個數** | $BIT$ + 離線 | |

### 滑動窗口
| 關鍵字 | 技巧 | 可能延伸 |
| - | - | - |
| 不固定大小 | 雙指標 | |
| 固定大小 | 單調對列 | 正方形 |

# 語法

## 特殊函式

### stable\_sort

### emplace\_back

### assert

## 好用語法

### enum

`enum` 是一個以數字來定義 `token` 的快速工具，例如：

```c++
enum Piece {
    King, Queen, Bishop, Knight, Pawn
}
```

等同於

```c++
int King = 0;
int Queen = 1;
int Bishop = 2;
int Knight = 3;
int Pawn = 4;
```

於是，這個語法可以**快速定義狀態，並以 `token` 來表示**，增加易讀性。

### switch

`switch` 是一連串的狀態切換，例如：

```c++
if (type == 1) {
    //??
} else if (type == 2) {
    //?
} else {
    //!!
}
```

等同於

```c++
switch (type) {
case 1:
    //??
    break;
case 2:
    //?
    break;
default:
    //!!
}
```

注意，**每個 `case` 必須要 `break` 才能跳出 `switch`**，不然會繼續跑下去。

### class

### bitset

### template

# 技巧

## 二分搜

### lower /  upper\_bound()

### 單調性 + 求極值

若題目要求某條件的**極端值（最大或最小）**，並且當此條件增加時，連帶改變的結果值**單調（遞增或遞減）**，即可二分搜此條件。

#### 轉移數學式達成條件

[Gift Set - CF (div.3)](https://codeforces.com/contest/1538/problem/G)

### 浮點數二分搜

### minimax

若題目要**最大化某條件的最小值（反之亦然）**，則可**直接二分搜該條件**。

#### 例題：CF Splitting an Array

題目敘述：給定 $\langle a_n \rangle$ 與 $k$，若要分割此數列為 $k$ 小段，並使**所有段落總和的最大值最小**，請求出此總和。

解法：發現是 $minimax$ 問題，於是**直接二分搜**段落總和，並**貪心**的把能納入一個段落的 $a_i$ 加入此段落，最後算出：**至少需要幾段才能使所有段落的總和皆 $\le mid$**，即可與 $k$ 比較更改上下界。

### 第 k 小 / 大

### 0/1 分數規劃

### 門檻二分搜

如果要選取數列中某些項目，使總和符合條件，但數列中的項目太多，就可以設立門檻，也就是若選取數列中所有**在某條件之下**的項目，其總和可否達到條件。可證明若搜出此條件 $x$，則剩下要選的項目的條件必定是 $x + 1$。

#### 例題：ABC389E Square Price (此題的答對數比F題少一半!!)

題目敘述：給你一些商品 $P = [p_1, p_2, \ldots, p_n]$，若選取 $k$ 個商品 $p_i$，需花費 $k^2 \times p_i$，請問若有 $M$ 元，至多可以買幾個商品？

解法：發現花費 $k^2 \times p_i$ 其實等價於：購買商品價格為
$$
1\times p_i+ 3\times p_i+5\times p_i + \cdots + (2\times i - 1) \times p_i
$$

而要買最多商品可以**貪心的先選便宜的買**。但是會發現商品太多無法直接搜。

於是可以**二分搜門檻 $x$ 使選擇所有價格 $\le x$ 的商品選完後，總和 $\le M$**。再透過證明，發現剩下的錢其實**都要買下價格 $x + 1$ 的商品**，因此答案是：
所有價格 $\le x$ 的商品個數 $+$ 剩下的錢 $\div\ (x + 1)$

### 中位數二分搜

### 整數三分搜

### 浮點數三分搜

### 離散化

離散化是當**輸入極大**，但是**只需考慮數值差異**即可解題的技巧。可以使用 `unique` 加 `lower_bound` 快速寫出。

```c++
template <typename T>
class discretize {
public:
    template <class ... Args>
    void add(Args ... args) {
        (ori.emplace_back(args), ...);
    }

    void build() {
        // 先排序
        sort(all(ori));
        // 再用 unique 去重, erase 刪去多餘項目
        ori.erase(unique(all(ori)), ori.end());
    }

    int get(T x) {
        return lower_bound(all(ori), x) - ori.begin() + 1;
    }

    int size() {
        return ori.size();
    }

private: 
    vector<T> ori;
};
```

## 枚舉

### 全排列枚舉

使用 `do {} while {next_permunitation()}`，即可使用全排列枚舉。注意序列必須**先排序**才能排出所有排列。

$N \approx 13$ 可使 $O(N!)$ 達到一秒。

### 二元枚舉

使用位元可使二元枚舉實作更簡單。

```c++
for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < n; j++) {
        if ((i >> j) & 1) {
            // i的第 j 低位元 = 1
        } else {
            // i的第 j 低位元 = 0
        }
    }
}
```

$N \approx 20$ 可使 $O(2^N)$ 達到一秒。

### 折半枚舉

### 枚舉倍數

### 遞迴枚舉

#### 一般

遞迴枚舉可以枚舉**一項變數**或是**座標**。請先觀察出**特性**再解題。

##### 例題：K皇后

題目敘述：請輸出所有可能性，使在 $N \times N$ 放入 $N$ 隻皇后且互不攻擊。 $(0 \le N \le 12)$

解法：**發現**一排至多只能放一隻皇后，因此可使用第 $n$ 排為遞迴對象，每排再確認每項可否放皇后即可。

#### 特殊情況

若有特例，則必須在遞迴時考慮進去。

##### 例題：ABC318D General Weighted Max Matching

題目敘述：有一個完全圖，請選出一些邊，使這些邊的頭尾不相連的同時，讓邊權重總和最大。 $(1 \le N \le 16, 1 \le W \le 10^9)$

解法：**發現**當點是偶數時，必定是選 點數 $\div\ 2$ 條邊會最好（貪心），而若是奇數時至多只有一點沒有編連接。使用這個特性就可以遞迴枚舉。

### 好的枚舉順序

#### 枚舉左右界

```c++
for (int l = 0; l < n; l++) {
    for (int r = l; r < n; r++) {
        // Do something
    }
}
```

#### 枚舉區間距離

```c++
for (int len = 1; len <= n; len++) {
    for (int l = 0; l + len <= r; l++) {
        int r = len + l;
        // Do something
    }
}
```

#### 由內向外

```c++
for (int c = 0; c < n; c++) {
    for (int len = 0; len < n; len++) {
        int l1 = c - len, r1 = c + len;
        // Do something
        
        int l2 = c - len, r2 = c + 1 + len;
        // Do something
    }
}
```

## 數學

### 分數

### 向量與線

#### 共線

若有點集 $(X_i, Y_i)$，可以使用 $m_{\overline{ij}} = m_{\overline{ik}}$ 判斷是否點 $i, j, k$ 共線。

#### 直角

若有點集 $(X_i, Y_i)$，可以使用 $m_{\overline{ij}} \times m_{\overline{ik}} = -1$ 判斷是否 $\overline{ij} \bot \overline{ik}$

### 因數質數

#### 篩法

```c++
vector<bool> prime(SZ + 1, 1);
prime[0] = prime[1] = 0;

for (int i = 2; i * i <= SZ; i++) {
    if (prime[i] == 0) continue;
    for (int j = 2 * i; j <= SZ; j += i) prime[j] = 0;
}

```

#### 枚舉 1 ~ n 的倍數

如果題目與**一個數所有可能的因數**有關，即可使用此技巧。

```c++
for (int i = 1; i <= MAX_V; i++) {
    for (int j = i; j <= MAX_V; j += i) {
        //!!
    }
}
```

##### 例題：ABC393E GCD of Subset

題目敘述：$\exists \langle a_n\rangle$，請求出當 $a_i$ 必須選擇且必須選擇 $K$ 個 $\langle a_n\rangle$ 中的數時，最大公因數為和。

解法：
1. $gcd$ 要存在 $p$ 代表： $a_i$ 有因數 $p \wedge p$ 在其他數中出現超過 $K - 1$ 次。
2. 可以枚舉 1 ~ n 的倍數，用 $factor\_cnt[i]$ 儲存因數 $i$ 在所有數中出現幾次。

```c++
for (int i = 1; i <= MAX_V; i++) {
    for (int j = i; j <= MAX_V; j += i) {
        // cnt[i] := i 在 a 中出現幾次
        factor_cnt[i] += cnt[j];
    }
}
```

3. 再來只要 $i = 1, i \rightarrow MAX\_V$，即可確認當選擇 $i$ 的倍數時，最大的 $gcd$ 一定可以是 $i$。

```c++
for (int i = 1; i <= MAX_V; i++) {
    // 如果因數出現次數不足即刪去
    if (factor_cnt[i] < K) continue;
    
    for (int j = i; j <= MAX_V; j += i) {
        ans[j] = max(ans[j], i);
    }
}
```

#### 質因數分解

若分解數 $n \le 10^{12}$，可使用 $O(\sqrt n)$ 暴力拆解所有質數。

```c++
for (int i = 2; i * i < n; i++) {
    int cnt = 0;
    while (n % i == 0) {
        cnt++;
        n /= i;
    }
    // 加入分解 i^cnt
    prime_factorization.emplace_back(i, cnt);
}
// 特例處理
if (n > 1) prime_factorization.emplace_back(n, 1);
```

若查詢 $q \le 2 \times 10^5$ 而查詢數為 $n \le 10^7$，這時就須使用 $\text{Smallest Prime Factor}$ 來降低每次查詢的時間複雜度從 $O($每數字$\sqrt n) \rightarrow O($所有 $\le n$ 的數皆 $\log n)$。

```c++
struct SPF {
    int ma;
    vector<int> spfList;

    SPF(int maxNum) : spfList(maxNum + 1), ma(maxNum) {
        for (int i = 2; i <= maxNum; i++) {
            if (spfList[i] == 0) {
                for (int j = i; j <= maxNum; j += i) {
                    if (spfList[j] == 0) spfList[j] = i;
                }
            }
        }
    }

    vector<array<int, 2>> prime_factorization(int num) {
        assert(num <= ma);
        vector<array<int, 2>> res;

        int lstPrime = spfList[num];
        int cnt = 0;
        while (num != 1) {
            if (spfList[num] == lstPrime) cnt++;
            else {
                res.push_back({lstPrime, cnt});
                cnt = 1;
                lstPrime = spfList[num];
            }
            num /= spfList[num];
        }
        res.push_back({lstPrime, cnt});

        return res;
    }
};
```

#### 數學式轉成因式分解

通常這類題目會有一個數學式，而要求出有幾個值可以滿足條件，這時就可以嘗試將式子轉成
$$
A\times B = \text{origin equation}
$$
，就可以枚舉所有因數求解。

##### 例題：ABC420G sqrt(n²+n+X) (極難)

題目敘述：給定 $\sqrt{n^2 + n + X}$ 與 $X$，請求出共有多少 $n$ 可以使式子為整數？

解法：

1. 嘗試將 $m = \sqrt{n^2 + n + X}$ 轉成 $A \times B = C$ 的形式：
$$
\begin{gathered}
m = \sqrt{n^2 + n + X}\\
\Longleftrightarrow m^2 = n^2 + n + X\\
\Longleftrightarrow X = m^2 - n^2 - n\\
\Longleftrightarrow X = m^2 - (n + \frac{1}{2})^2 + \frac{1}{4}\\
\Longleftrightarrow 4X = 4m^2 - 4(n + \frac{1}{2})^2 + 1\\
\Longleftrightarrow 4X = (2m)^2 - (2n + 1)^2 + 1\\
\Longleftrightarrow 4X - 1 = (2m - 2n - 1)(2m + 2n + 1)
\end{gathered}
$$

2. 發現轉成這樣的形式就可以推出 $n$：

$$
\begin{gathered}
4X - 1 = (2m - 2n - 1)(2m + 2n + 1)\\
\text{let } (2m - 2n - 1) = d, (2m + 2n + 1) = \frac{4X - 1}{d}\\
(2m + 2n + 1) - (2m - 2n - 1) = 4n + 2\\
n = \frac{(2m + 2n + 1) - (2m - 2n - 1) - 2}{4} = \frac{\frac{4X - 1}{d} - d - 2}{4}
\end{gathered}
$$

3. 因此只需枚舉 $d$ 就可以判斷並列出答案。

### 取餘

#### 性質

1. 分配律：**只有加減乘**。
2. 同餘： $$\text{if } a - b = mq \Longrightarrow a \equiv b \pmod m$$

#### 質數 MOD 除法

若模數為質數，則利用費馬小定理：
$$
\text{Let } p \text{ is a prime, then } \forall a \in \mathbb{Z}\quad a^p \equiv a \pmod{p}\
\Longrightarrow a^{p-1} \equiv 1 \pmod{p}
$$
可推出
$$
a \times a^{p-2} \pmod{p} \equiv 1 \Longrightarrow a^{-1} \equiv a^{p-2} \pmod{p}
$$
最後
$$
\frac{b}{a} = b \times a^{-1} \equiv b \times a^{p-2} \pmod{p}
$$
因此，除法 $b \div a$ 可表示成 $b \times a^{MOD - 2}$ 若模數為質數。

```c++
template<int MOD>
struct Modint {
    long long v;
    Modint(long long _v = 0) {
        v = _v % MOD;
        if (v < 0) v += MOD;
    }
    Modint operator+(const Modint &other) const {
        return Modint(v + other.v);
    }
    Modint& operator+=(const Modint &other)  {
        v += other.v;
        if (v >= MOD) v -= MOD;
        return *this;
    }
    Modint operator-(const Modint &other) const {
        return Modint(v - other.v);
    }
    Modint& operator-=(const Modint &other) {
        v -= other.v;
        if (v < 0) v += MOD;
        return *this;
    }
    Modint operator*(const Modint &other) const {
        return Modint(v * other.v);
    }
    Modint& operator*=(const Modint &other) {
        v = v * other.v % MOD;
        return *this;
    }
    Modint operator/(const Modint &other) const {
        return *this * other.inv();
    }
    Modint operator/=(const Modint &other) {
        return *this *= other.inv();
    }
    Modint pow(long long times) const {
        Modint base = *this;
        Modint res = 1;
        while (times) {
            if (times & 1) res *= base;
            base *= base;
            times >>= 1;
        }
        return res;
    }
    // 模運算乘法反元素
    Modint inv() const {
        return pow(MOD - 2);
    }
};
```

#### 安全取餘

注意減法取餘時，有機會計算出的原始答案 $< 0$，因此需要再加上 $mod$ 數再取餘一次。程式碼：`((a % MOD) - (b % MOD) + MOD) % MOD`

### 後綴零

當數字有後綴零時，代表其因數包含 $2 \wedge 5$，因此只需判斷 `min(2 的個數, 5 的個數)` 即可。

### 快速冪

```c++
ll res = 1;
while (b > 0) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
    b >>= 1;
}
// 每次看 b 的最後一位 bit 是否是 1，如果是，就將答案乘上 a^2^{第 k 輪}
```

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

##### 例題：ABC236G Good Vertices (極難)

題目敘述：有一些有向邊會依時間 $1, 2, \ldots, T$ 依序建立，如果一個點可以在恰好 $L$ 步下抵達，則此點是好點。請求出此點最快在何時是好點？
點數 $n \le 100\quad T \le n^2\quad L \le 10^9$

解法：
1. 發現會依時間建邊，可以**建模成以時間為權重的具權有向圖**。
2. 如此建模後可以：`dp[i][j][k] :=在時間 i 時走 j 步可否抵達 k 點`，但是會超時。
3. 發現題目要求的是時間愈早愈好，因此可以改良 `dp[i][j] := 走 i 步抵達 j 點時，最快何時可以抵達`，而**何時可以抵達就是路徑中最大的權重**。
4. 因此可以寫出轉移為：
$$
dp[i][v] = \min_{1 \le u \le n} \max\{dp[i - 1][u], W_{u \rightarrow v}\}
$$
但是還是會超時。
5. 想到用**矩陣優化**，由於一次要更新所有點的最小路徑最大權重，因此設定矩陣為：
$$
\begin{bmatrix}
dp[i][1] \\ dp[i][2] \\ \vdots \\ dp[i][n]
\end{bmatrix} = 
\text{Transformation Matrix}
\bigoplus
\begin{bmatrix}
dp[i - 1][1] \\ dp[i - 1][2] \\ \vdots \\ dp[i - 1][n]
\end{bmatrix}
$$
6. 根據矩陣乘法，會發現轉移矩陣可以寫成：
$$
\begin{bmatrix}
W_{1\rightarrow 1} & W_{2\rightarrow 1} & \cdots & W_{n\rightarrow 1} \\
W_{1\rightarrow 2} & W_{2\rightarrow 2} & \cdots & W_{n\rightarrow 2} \\
\vdots & \vdots & \ddots & \vdots \\
W_{1\rightarrow n} & W_{2\rightarrow n} & \cdots & W_{n\rightarrow n}
\end{bmatrix}
$$
而矩陣類乘法的運算 $(\bigoplus)$ 就是：
$$
\text{Result Matrix}_{ij} = \min_{1 \le k \le n} \max \{\text{Transformation Matrix}_{ik},\ \text{Input Matrix}_{kj}\}
$$
因此可以使用矩陣快速冪。

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

##### 例題： CSES Graph Paths II

題目敘述：給一些有權重 $w$ 的有向邊，求剛好走 $k$ 條邊 (可重複) 從 $1 \rightarrow n$ 時的最短路多長。
$n \le 100\quad k \le 10^9$

解法：發現 $k$ 很大，因此需要使用矩陣優化。將矩陣設為：
$$
A_{ij}:= \text{The minimun distance from i to j}
$$

而轉移矩陣可設為：
$$
B_{ij} := 
\begin{cases}
w_{i, j} & \text{if there is a way from i to j}\\
\infty
\end{cases}
$$

這時會發現，如果將矩陣乘法改成：
$$
(AB)_{ij} = \min_{r=1}^{n}A_{ir}B_{rj}
$$

則 $A \times B^k$ 就是走 $k$ 步時，所有點對最短路徑的結果。

#### 模板

```c++
struct Matrix {
    int n, m;
    vector<vector<ll>> mat;
    int MOD = 1e9 + 7;

    // 加法單位元素
    Matrix (int _n, int _m, bool multiply = 0) : mat(_n, vector<ll>(_m, -INF)) {
        n = _n; m = _m;

        if (multiply) {
            assert(n == m);
            *this = identity(n);
        }
    }

    // 乘法單位元素
    Matrix identity (int sz) {
        Matrix res(sz, sz);
        for (int i = 0; i < sz; i++) res.mat[i][i] = 1;
        return res;
    }

    Matrix operator*(const Matrix &b) const {
        assert(m == b.n);

        Matrix res(n, b.m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < b.m; j++) {
                for (int k = 0; k < m; k++) {
                    res.mat[i][j] += mat[i][k] * b.mat[k][j];
                    if (res.mat[i][j] >= MOD) res.mat[i][j] %= MOD;
                }
            }
        }

        return res;
    }

    // 方陣快速冪
    Matrix pow(ll t) {
        assert(n == m);

        Matrix res = identity(n);
        Matrix base = *this;

        while (t) {
            if (t & 1) res = res * base;
            base = base * base;
            t >>= 1;
        }

        return res;
    }

    void print() {
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cout << this->mat[i][j] << " \n"[j == m - 1];
    }
};
```

### 進制轉換

透過進制轉換，可以利用十進位的數字代表一串數列，甚至可以做到：
$O(\log_{10} n)$ 創造出字典序第 $n$ 小的數列 $\langle a_n \rangle \in [0, k]$。

#### 模板

```c++
// from 十進位數字 base 幾進制 bit 取幾位
vector<int> numeralSys(int from, int base, int bit) {
    vector<int> res;
    
    for (int i = 0; i < bit; i++) {
        res.emplace_back(from % base);
        from -= from % base;
        from /= base;
    }
    
    reverse(all(res));
    return res;
}
```

### 大數運算

#### 模板

```c++
// 大數取餘
string mod(string a, int b) {
    int r = 0;
    for (char c : a) {
        r = (r * 10 + (c - '0')) % b;
    }
    return to_string(r);
}
```

### 有交集

若兩區間 $[l_1, r_1], [l_2, r_2]$ 有交集，則判斷式為：
$$
l_1 \le r_2 \wedge l_2 \le r_1
$$

就是**左端點不要跑到對方右端點的右邊**。 

## 位元

### 左右移

### XOR 特性

### 位元函式

### 狀態壓縮

### 前綴 XOR

## 前綴和與差分

## 排序

### 自定義比較函式

## 優化

### 記憶體複製優化

如果頻繁在迴圈內建立陣列如 `vector` 容易超時，因此可以改成：

1.**先建立**，每次迴圈內初始化。
2. 用 `取址&` 將答案輸出在同一陣列裡。

如果還是太慢，就使用 `C++` 原生陣列。
```c++
int aFunction(int *arr /*陣列會退化成指標*/) {
    int cnt = 0;
    
    for (int i = 0; i < n; i++) {
        arr[cnt++] = i;
    }
    
    return cnt;//回傳最後的位置
}
```

### 重複計算優化

如果計算時，有些部分重複計算，就可以改變計算順序去優化。


#### 例題

題目敘述：定義對稱度為：
$$
A(l, r) = \sum_{i = 0}^{\lfloor \frac{r - l}{2} \rfloor} |h_{l + i} - h_{r - i}|
$$
請在 $O(n^2)$ 求出所有數對 $(l, r)$ 的對稱度。

解法：發現 $A(l, r) = A(l + 1, r - 1) + |h_l - h_r|$，所以可以從 $C_{\text{mid}}$ 開始向外擴張，就能算出 $\forall i \in [0, ?]\quad A(C - i, C + i)$。

## 掃描線

### 布幕拉開法

可以想像掃描線是一個布幕，每次拉開就會多一個像被看見，而再根據這個項目更新現在的答案。

## 雙向搜尋

## 雙指標

### 重複項目計數

```c++
sort(a.begin(), a.end());

for (int i = 0, j = 0; i < n; i = j) {
    while (j < n && a[i] == a[j]) j++;
    // j - i 就是 a[i] 有幾項
    int len = j - i;
}
```

### 同向雙指標

Too easy

### 反向雙指標

此類型可以求出$a_i + a_j > S$ 的組別數。

```c++
for (int i = 0, j = n - 1; i < n; i++) {
    while (j > i && a[i] + a[j] >= S) j--;
    
    cnt += n - max(i, j);
}
```

此類型可以求出 $a_i + a_j = S$ 的組別數。

```c++
for (int i = 0; i < n; i++) {
    for (int l = i + 1, r1 = n - 1, r2 = n - 1; l < r2; l++) {
        while (r1 > l && a[i] + a[l] + a[r1] >= S) r1--;
        while (r2 > l && a[i] + a[l] + a[r2] > S) r2--;

        ans += r2 - max(l, r1);
    }
}
```

## 隨機

TODO

## 打表

TODO

## 樹

### 樹壓平

樹壓平可以使樹從二維變成一維。藉由紀錄遍歷樹的順序，與子樹中的最大 $id$，就可以壓成一維陣列來表示。

```c++
int id[] = {}, maxSubtreeId[] = {};
int idx = 0;

void dfs(int x, int lst) {
    id[x] = ++idx;
    for (auto y : e[x]) {
        if (y == lst) continue;
        dfs(y, x);
    }
    maxSubtreeId[x] = idx;
}

dfs(root, -1);
```

# 思考技巧

## 分治

### 左右分治

左右分治的精隨就是 **只考慮橫跨左右的子問題** 就好，而處理這個問題可以使用 **$O(n)$** 解決。

#### 原理

將序列問題拆成全部在左邊，橫跨左右邊，全部在右邊三段，而全左與全右可以化為子問題，因只需處理橫跨左右邊的問題即可。

#### 例題：`ABC441E` A \> B substring

題目敘述：請求出 $\langle S_n\rangle \in [A, B, C]$ 如 $ABCAB$ 中，所有滿足：$A$ 個數 $>$ $B$ 個數 的子字串 $(substring)$ 個數。

解法：使用左右分治，處理橫跨左右邊的問題即可。注意可以使用 **$O(n)$** 解題，因此不用想太難的解法。

## 貪心

### 能選就選

如果可**證明先選必定比延後再選還佳**，即為能選就選的貪心。

#### 例題：LeetCode392 Is Subsequence

題目敘述：給定兩字串 $s, t$，請判斷 $s$ 是否為 $t$ 的子字串。

解法：發現若越先選 $s_i = t_j$，則會比後選**更有機會出現 $s_p = t_q$ 的情況**，因此先選一定最佳。

### 配對貪心

#### 重排不等式應用

$$
\displaylines{
\text{if } \exists X = [x_1, x_2, \ldots, x_n] \wedge \exists Y = [y_1, y_2, \ldots, y_n] \\
\wedge \quad x_i < y_i \quad \forall i\\
\text{then if sort(X) and sort(Y), }\\
x_i < y_i \quad \forall i
}
$$

這代表**若有一種排列滿足某種配對，則排序後的兩數列也必滿足此配對**，反之亦然。

#### 循環配對

若要求出讓 $x_i, y_i$ 配對後的 $\max \text{ or } \min |x_i - y_i|$，就可以枚舉所有循環差 $d$，讓 $x_i \vee y_{(i + d) \bmod n}$ 配對。

由於重排不等式應用必定正確，因此就可以用循環的方式枚舉所有配對方式，就可以解題。

### 反悔貪心

有些貪心可以中途反悔，因為**反悔後反而會更好**。

#### 例題

題目敘述：請求出一數列 $\langle a_n \rangle$ 的最長子序列長度，使這個序列 $\langle a'_n \rangle$ 滿足：

$$
\begin{aligned}
a_1 > a_2 < a_3 > \cdots \lessgtr a_n\\
a_1 < a_2 > a_3 < \cdots \lessgtr a_n\\
\end{aligned}
$$

解法：
1. 初始時先選能選的一定最好。
2. 如果將要選擇小的數，但是遇到比之前選的大數還要大，那就改選這個。因為：**若在選擇大數時選愈大的數，之後選小數的可能性更大**，因此**反悔**之前的選擇。反之亦然。

### 鴿籠原理

TODO

### 霍夫曼編碼

霍夫曼編碼可以高效壓縮資料，通常以**沒有前綴重疊的二進制編碼**完成。一種貪心實現如下：

1. 紀錄所有字元出現的次數於 `cnt[]` 中。
2. 發現每次要區分兩個字元時，**先選擇兩個出現次數最小的字元**必定最好。以交換的概念證明，若選擇一個出現次數更多的字元，則必定會使用更多的 `bit` 來表示次數多的字元，故得證。
3. 最後將合併的二元樹之邊，一邊標 $0$，一邊標 $1$ 即是答案。

### 區間貪心

區間貪心的精隨是：每次選擇 `右 / 左` 界最 `右 / 左` 的區間，對 `右 / 左` 界做操作。

#### 最少區間切割次數

題目敘述：若將區間看成疊在一起的蛋糕，則問題在問：若一次切一刀 (一次切到底)，且每個蛋糕都要被切到一刀，問最少需要幾刀？

解法：**依序對 `右` 界最 `左` 的區間，對 `右` 界切一刀**，則所有包含此右界的區間皆有被切一刀，跳過這些區間。

證明：若對右界以左的某個點切一刀，則**因為此區間是目前右界最左的，因此不會存在一個區間完全位於此區間以右**，不如選擇能切最多區間的右界。

#### 最少區間覆蓋問題

題目敘述：請求最少的區間使所有空格都能被至少一個區間蓋住。

解法：對 `右` 界最 `左` 的區間，對 `右` 界以內的**區間左界作紀錄，找出可以延伸最長的區間**，選定此區間進行下一次操作。

證明：每次選延伸最長的一定有更多機會找到下一個可接應的區間。時間複雜度因均攤為 $O(n \log n)$ 排序 + $O(n)$ 找最長區間。

#### 最多區間選擇問題

題目敘述：有一掃描線，若每個時間點只能選一個正在被掃到的區間，請求至多能選多少區間？

解法：對所有正在被掃的區間中，選擇`右` 界最 `左` 的區間。

證明：若選擇一個還可以繼續被掃的區間，不如與快要不能掃的區間交換，一定最好。

### 排序貪心

這類貪心只需排序特定數值即是最佳解，而在猜測特定數值時，可以使用排序的基本 **交換相鄰兩數** 來驗證貪心的正確性。

#### 例題：NTUCPCOJ728 烏龜塔

題目敘述：有一些烏龜重 $W_i$，且他們過動度 $T_i$，當他們疊成一座塔時，烏龜會想要出來，而一次出來的麻煩度是：
$$
T_i \times\sum_{k=1}^{i-1} W_k
$$

請求出所有烏龜的最小麻煩度，也就是：
$$
\sum_{i=1}^{n}(T_i \times \sum_{k=1}^{i-1}W_k)
$$

解法：先用交換的方式嘗試寫出兩烏龜 $i, j$ 交換，且 $i$ 在上，$j$ 在下時，對整體麻煩度的影響。

$$
\begin{gathered}
\text{Let } S = \sum_{k = 1}^{i - 1} W_k,\\
\text{cost of origin} = T_i \times S + T_j \times (S + W_i)\\
\text{cost of new} = T_j \times S + T_i \times (S + W_j)\\
\text{cost of swapping} = \text{cost of new} - \text{cost of origin} = T_i \times W_j - T_j \times W_i\\
\text{if we want to swap i and j, then cost of swapping} \le 0\\
T_i \times W_j - T_j \times W_i \le 0\\
T_i \times W_j \le T_j \times W_i\\
\frac{T_i}{W_i} \le \frac{T_j}{W_j}\\
\text{thus, we should sort them with } \frac{T_i}{W_i}
\end{gathered}
$$

## 圖論建模

### 自加權重

有些模型可以建模成有權重的圖。

| 情況 | 如何建模 | 效果 |
| - | - | - |
| 依時間加入(減去)邊 | 將**邊的權重設為時間**加入圖 | 如果限制最大邊權為 $k_{\max}$，代表這條路徑只能走時間 $k_{\max}$ 之前的邊 |

## 動態規劃

### 記憶化搜索 

請注意，若記憶化的圖不是 $\text{DAG}$ (有向無環圖)， $\text{dp}$ 互相依賴會爆炸。

### 表達式 dp

如果表達式中，可以明確知道 **優先順序**，就可以把表達式拆成：

$$
(一串相同符號運算)\ \bigoplus\ (一串相同符號運算)\ \bigoplus\ (一串相同符號運算) \cdots
$$

也就是：

$$
(v_1 \times v_2 \times \cdots \times v_n) + (v_{n+1} \times v_{n+2} \times \cdots \times v_m) + \cdots + (v_p \times v_{p+1} \times \cdots \times v_q)
$$

就可以定義 `dp[i] := 走到 v_i 之後的項目做運算最佳結果是多少`，用 $O(n^2)$ 算出所有切斷此連續符號運算的位置，用 $\text{Memorize Search}$ 求出答案。

```c++
// 如果是 + 與 *
 auto f = [&](auto self, int index) -> int {
        if (index >= sz) {
            return 0;
        }

        if (visi[index]) return dp[index];
        visi[index] = 1;

        ull res = 1e9;
        ull curr = 1;
        for (int j = index; j < sz; j++) {
            curr *= tmp[j];
            res = min(res, curr + self(self, j + 1));
        }
        return dp[index] = res;
};
```

### 二維地圖 dp

若是二維地圖，但是**走法或條件與其他格子相關**，使用 dp 會比圖論更輕鬆。推薦二維地圖皆使用 dp 解題，有更小的常數。

#### 例題：ABC443E Climbing Silver

題目敘述：一個 $N \times N$ 地圖 $\in$ `.` `#`，從 $(N, C)$ 開始，每次可以往 $(r - 1, c - 1), (r - 1, c), (r - 1, c + 1)$ 走。若遇到 `.` 可以走進去，若遇到 `#` 且 $\forall i \in [r + 1, N]$ 的 $(i, c)$ 都是 `#`，就可以把牆挖掉走進去。請求出可不可以走到 $\forall i \in [1, N]\quad (1, i)$？ 

預期 $O(n^2)$。

解法：使用 `dp[r][c] := 是否可以走到 (r, c)`，每次 `.` 轉移就是：
$$
dp[r][c] = 1 \text{ if } \max
\begin{aligned}
dp[r + 1][c - 1]\\
dp[r + 1][c]\\
dp[r + 1][c + 1]
\end{aligned} = 1
$$

若是 `#`，則可以先維護每一列最底下的牆壁在哪 $lowestWall_{\ \ using\ O(n)}$，當走到此列最下的牆壁時，如果可以抵達，就把他上面全部設為可達，因為一定可以把這一列的牆壁全打掉。

#### 特殊轉移

有些題目利用走法的限制 (如只能往右和往上走)，可以發現所有步數恰為 $k$ 的格子都恰好在**一個斜線上**，這時就可以直接**依斜線枚舉**來轉移。

```c++
for (int r = 0; r <= min(n - 1, step); r++) {
    int c = step - r;

    if (c >= n) continue;

    if (c + 1 < n) PUSH (r, c + 1) 轉移
    if (r + 1 < n) PUSH (r + 1, c) 轉移
}
```

### 樹 dp

#### 節點傳遞 dp

若在遍歷樹時， $dp \approx dp[x] = dp[y] + k$，就是以節點傳遞的 dp。可計算**子樹大小**。

#### 子樹合併 dp

這類 dp 每次會**合併父節點底下其中一個子樹**，完整 dp 如下：
1. 計算**未被合併**的子樹的答案。
2. 計算**已被 $x$ 合併**的樹的答案。
3. 計算**要合併的 $y$ 子樹**的答案。
4. 計算**父節點以上**的答案。
5. 將答案更新為
$$
\begin{aligned}
\text{answer} =\
& \text{answer of Tree }x\\
&+ \text{answer of Tree }y\\
&+ \text{answer of Tree unmerged}\\
&+ \text{answer of Tree above their parents}
\end{aligned}
$$
7. 將 $\text{answer of Tree }x$ 更新為
$$
\max 
\begin{cases}
\text{curent best answer} + \text{changes of Tree }y & \text{not using Tree }y\\
\text{best answer of Tree }y + \text{answer of Tree merged} & \text{using Tree }y
\end{cases}
$$

### 倍增

倍增是以 $2^k$ 來加速運算的一種 `技巧性 dp`。狀態與轉移幾乎每題一樣：`dp[i][j] := 從 j 開始走 2^i 步，走到的答案為何`。轉移式為：
$$dp[i][j] = dp[i - 1][j] \oplus dp[i - 1][j + 2^i]$$

### 將狀態設為答案

### 根據 dp 表優化

有時**列出 $\text{dp}$ 表**後，會發現轉移其實只使用部分表格，而其他可省略，因此可以直接優化表大小，並加速。

| 可能的優化 | 優化方式 |
| - | - |
| $\text{dp}$ 只和上一排有關 | 設 $id_1 = 0, id_2 = 1$，以 $id_1$ 為現在這排， $id_2$ 為上一排，更新完成後再 `swap(id1, id2)`，最後初始化上一排的資料，就可以把表大小壓成 $O(2 \times \text{lasted})$。|


### 更多優化

這些優化需要**列出 $\text{dp}$ 表**觀察性質，並以特定資料結構解題。

| 關鍵性質 | 優化方式 |
| - | - |
| 連續和 | 前綴和 |
| 一個變數小，其他皆 $\ge 10^9$ | 矩陣 (小的變數就是矩陣乘法的成本) |

# 演算法

## 序列

## 表達式

## 最短路

### BFS

#### 回溯解

可使用 `p[x]` 紀錄 x 的父親，就可以在 $O(\text{path length})$ 內找出此路徑。

#### 01 BFS

$01\ BFS$ 是 $Dijkstra$ 的簡化版，使用 $deque$ 將邊權 $=0$ 的放在前面，邊權 $=1$ 的放在後面，於是可以快速的求出最短路。

### Dijkstra

$\text{Dijkstra}$ 是貪心的 $\text{BFS}$，貪心如下：

1. 選定所有節點中**目前已抵達的最近的葉節點**。
2. 枚舉所有邊，將這些有連接的點記錄起來。
3. 重複直到找到終點。

#### 模板

```c++
template<typename T>
struct Dijkstra {
    int n; // 節點數
    vector<vector<pair<int, T>>> e;
    vector<T> dis;

    Dijkstra(int _n, T inf) : n(_n), e(_n + 1), dis(_n + 1, inf) {};

    void add(int u, int v, T w) {
        e[u].emplace_back(v, w);
    }

    vector<T> shortestPath(int st) {
        priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pool;

        dis[st] = 0;
        pool.push({dis[st], st});

        while (pool.size()) {
            auto [w, x] = pool.top();
            pool.pop();

            for (auto [y, w2] : e[x]) {
                if (dis[x] + w2 < dis[y]) {
                    dis[y] = dis[x] + w2;
                    pool.push({dis[y], y});
                }
            }
        }

        return dis;
    }
};
```

#### 例題：CSES Investigation TODO

#### 多源 Dijkstra

可以建立一個超源頭 $S$ 並連接 $S \rightarrow s_1, S \rightarrow s_2, \ldots, S \rightarrow s_k$，就可以在不破壞架構的情況下模擬出多源的效果。

### Floyd Warshall

$\text{Floyd Warshall}$ 是一種特定 $\text{dp}$ 的演算法， $\text{dp}$ 定義如下：
$$
dp[k][i][j]:= 只經過\ 1 \sim k\ 的點，從點\ i\ 至點\ j\ 的最短路
$$
而透過枚舉順序的優化，可以用 $O(n^3)$ 的時間與 $O(n^2)$ 的空間實作。以下是優化證明：

1. 列出轉移式：
$$
dp[k][i][j] = \min
\begin{cases}
dp[k - 1][i][k] + dis_{k \rightarrow j} & \text{if visit k}\\
dp[k - 1][i][j] & \text{if not visit k}\\
\end{cases}
$$
2. 會發現若省略 $[k]$，即使會使 $dp[i][j]$ 取到理應經過 $k$ 枚舉的新值，由於運算式為 $\min$，因此取最新的資料也無妨。
3. 因此**先枚舉 $k$，再枚舉 $i \vee j$**，空間就可從 $O(n^3) \rightarrow O(n^2)$。

#### 模板

```c++
for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        }
    }
}
```

#### 有向圖最小環

1. 跑一次 $Floyd\ Warshall$ 求出所有點對距離。**(包含 $dis[x][x]$)**
2. 發現所有的 $dis[x][x]$ 就是以 $x$ 為頂點的最小環，於是最後在 $O(V)$ 做一次 $\min dis[i][i]$ 即可。

```c++
int ans = INF;

for (int k = 0; k < n; k++) {
    /*Floyd Warshall*/
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        }
    }
}

for (int i = 0; i < n; i++) {
    /*更新最小環*/
    ans = min(ans, dp[i][i]);
}
```


#### 無向圖最小環

跑一個特殊的 $Floyd\ Warshall$ ，在**每次更新 $dis[i][j]$ 之前**，先更新最小環 $dp[i][j] + dis_{i \rightarrow k} + dis_{k \rightarrow j}$。

若直接使用 $dp[i][i]$，會出現如 點 $A \rightarrow$ 點 $B \rightarrow$ 點 $A$ 的假環。所以要在 點 $k$ 尚未更新之前，先使用現有的 $dp[i][j]\ (不含\ k)$ 與現有的邊 $dis_{i \rightarrow k}, dis_{k \rightarrow j}$ 更新最小環，就可以抹去假環。

請注意，必須**使用現有的邊來更新與 $k$ 相鄰的邊**，因為這時跟 $k$ 有關的 $dp$ 上更新好。 


```c++
int ans = INF;

/*初始圖的邊權重*/
vector<vector<int>> ori;

for (int k = 0; k < n; k++) {
    /*更新最小環*/
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < i; j++) {
            /*可保證不會出現假環*/
                ans = min(ans, ori[i][k] + ori[k][j] + dis[i][j]);
            }
        }

        /*Floyd Warshall*/
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
}
```


### Bellman Fold

$\text{Bellman Fold}$ 可解決有負邊的問題，他使用執行 **$V - 1$** 次對**所有邊**的 **鬆弛** 來更新最短路，也就是 $O(V \times E)$。

鬆弛就是執行 $\text{Dijkstra}$ 時以 **目前到此點的最短路 $+$ 此點出去的邊權重 來更新與其連接之節點的操作**。只是因為有負邊貪心會有誤，因此不得使用 $\text{Dijkstra}$。

就最糟情況而言 (筆筒圖)，至多執行 $V - 1$ 次所有邊的鬆弛就一定可以遍歷整個圖，因此若可以執行 $E$ 次以上的鬆弛，就代表有 **負環**。

```c++
template<typename T>
struct BellmanFold {
    int n;
    vector<tuple<int, int, T>> edge;
    vector<T> dis;

    BellmanFold(int _n, T inf) : dis(_n + 1, inf) {};

    void add(int u, int v, T w) {
        edge.emplace_back(u, v, w);
    }

    bool relax(int st) {
        bool valid = 0;

        int sz = edge.size();
        for (int i = 0; i < sz; i++) {
            auto [u, v, w] = edge[i];
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                valid = 1;
            }
        }

        return valid;
    }
};
```

#### 多源 Bellman Fold

可以建立一個超源頭 $S$ 並連接 $S \rightarrow s_1, S \rightarrow s_2, \ldots, S \rightarrow s_k$，就可以在不破壞架構的情況下模擬出多源的效果。

## 圖論

`visi` 可以使用 `int timer` 來判斷哪一點先走過。

### 名詞定義

#### 入度與出度

入度是有向圖一點有幾條邊**指向他**，出度是有向圖一點有幾條邊**從他出發**。

可證明若邊數 $\in$ 偶數，必定可以構造出每一點出度皆為偶數的圖。

### Kruskal's algorithm

$\text{Kruskal's algorithm}$ 用於**稀疏圖的最小生成樹**，其演算法如下：

1. 尋找點集中距離最近的一條邊。
2. 使用 $DSU$ 判斷此邊可否加入樹。
3. 若無法，跳至下一條最短邊。
4. 若可以，加入此邊。

時間複雜度為 $O(E \log E)$。

#### 例題 111北二2a.資料分組問題 (極難)

題目敘述：給你 $N$ 筆維度 $d$ 的資料，定義兩資料 $V_1 = [v_{1_1}, v_{1_2}, \ldots, v_{1_d}], V_2 = [v_{2_1}, v_{2_2}, \ldots, v_{2_d}]$ 的距離為：
$$
dis(V_1, V_2) = |v_{1_1} - v_{2_1}| + |v_{1_2} - v_{2_2}| + \cdots + |v_{1_d} - v_{2_d}|
$$

現在要將資料分成 $K$ 組，定義一個分組的好壞為：若組別中的最短距離愈大，則此分組愈好。
請找出兩個最好的分組，分成 $K$ 與 $K - 1$ 組時，這兩分組的組別中的最短距離最大值相同。（保證必定存在解）

解法：
1. ~~發現要最大化最小值，於是二分搜組別距離。~~ **如果這樣想就錯了！！**
2. 發現若分成 $K$ 組是最好的，則要分成 $K - 1$ 組其實就是合併現在這 $K$ 組的其中一組。
3. 若要使組別中的最短距離愈大，可以**貪心**的把目前距離最短的組別合併，這必然是最好的。
4. 發現**每次合併距離最短的兩組，這就是 $Kruskal's\ algorithm$。**
5. 若要使：分成 $K$ 與 $K - 1$ 組時，這兩分組的組別中的最短距離最大值相同，其實代表：當你在合併 $K$ 組變成 $K - 1$ 組時，**其實存在兩條要合併的最短邊，但是現在只合併一條而已。**
6. 因此把 $MST$ 的邊找出來，看看合併時有沒有連續合併兩條一樣長的邊，即為所求。

### Prim's algorithm

$\text{Prim's algorithm}$ 用於**稠密圖的最小生成樹**，寫法如下：
1. 尋找權重最小的一條邊，使這條邊**一端接在最小生成樹上，另一端接在未在樹上的節點**。
2. 加入此邊，並標記新加入的點為拜訪過，並維護與其相接的邊。

時間複雜度為 $O(E + V\log V)$。

```c++
template<typename T>
struct Prim {
    int n;
    vector<vector<pair<int, T>>> e;
    
    Prim(int _n) : n(_n), e(_n + 1) {};

    void add(int u, int v, T w) {
        e[u].emplace_back(v, w);
    }

    T mst() {
        int root = 1;
        T res = 0;
        vector<bool> visi(n + 1);
        visi[root] = 1;

        priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pool;
        
        for (auto [y, w] : e[root]) pool.push({w, y});
        while (pool.size()) {
            auto [w, x] = pool.top(); pool.pop();
            if (visi[x]) continue;
            visi[x] = 1;
            res += w;

            for (auto [y, w2] : e[x]) {
                if (visi[y]) continue;
                pool.push({w2, y});
            }
        }

        return res;
    }
};
```

### LCA

$\text{LCA (Lowest Common Ancestor)}$ 是一個**圖論題目**，當遇到樹中兩點距離即可用 $\text{LCA}$ 解出。

#### 模板

```c++
struct LCA {
    int n = -1;
    int h = -1;
    int root = -1;
    vector<vector<int>> e;
    vector<int> depth;
    vector<vector<int>> dp;

    LCA (int _n, int _root) : 
        n(_n),
        h(__lg(_n) + 1),
        root(_root),
        e(_n + 1),
        depth(_n + 1),
        dp(__lg(_n) + 2, vector<int>(_n + 1)
    ) {}

    void add(int a, int b) {
        e[a].emplace_back(b);
        e[b].emplace_back(a);
    }

    void build() {
        assert(n != -1);

        auto dfs = [&](auto self, int x, int lst) -> void {
            for (auto y : e[x]) {
                if (y == lst) continue;
                depth[y] = depth[x] + 1;
                dp[0][y] = x;
                self(self, y, x);
            }
        };
        dfs(dfs, root, -1);

        dp[0][root] = root;
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = dp[i - 1][dp[i - 1][j]];
            }
        }
    }

    int jump(int startNode, int step) {
        for (int i = 0; i <= h; i++) {
            if ((step >> i) & 1) {
                startNode = dp[i][startNode];
            }
        }
        return startNode;
    }

    int lca(int a, int b) {
        if (depth[a] > depth[b]) swap(a, b);
        b = jump(b, depth[b] - depth[a]);

        if (a == b) return a;

        for (int i = h; i >= 0; i--) {
            if (dp[i][a] != dp[i][b]) {
                a = dp[i][a];
                b = dp[i][b];
            }
        }

        return dp[0][a];
    }
    
    int dis(int a, int b) {
        int _lca = lca(a, b);
        return depth[a] - depth[_lca] + depth[b] - depth[_lca];
    }
};
```

### 樹上差分

若要在樹上做前綴和等操作，可利用 $\text{DFS}$ 遍歷樹的順序來作差分。

若要把路徑 $A \rightarrow B$ 上的點都做標記，可以在 $A, B$ 上標 `+1`，在 $\text{LCA}_{AB}$ 與 $\text{LCA}$ 的父節點標 `-1`，再**遍歷子節點後做加總**，就可以將路徑上所有點做標記。
 
# 資料結構

## 基礎容器

### 單調隊列

單調對列的基礎思考是：**若此項目可能成為答案，就放在資料結構裡**。

這種技術專門解決**固定大小的滑動窗口**，常以一般 `[]` 實作在結構 `前 / 後` 去 `加入 / 刪除` 項目。請注意實作時，初始的 `start_iterator` 跟 `end_iterator` 要設為 $-1$ 跟 $0$ (若是 `0-based`)。

#### 例題：LeetCode Sliding Window Maximum

題目敘述：給定數列，請求所有大小為 $k$ 的連續區間 (窗口) 的最大值。

解法：
1. 每次移動窗口時會加入一項並刪除一項。
2. 根據基本思考，若要加入新數，會發現若此數若**比之前出現的數還大**，**就代表之前這些數都沒機會成為最大值，可以刪除**；反之就留下來。
3. 若是刪除數，只須看隊列最前 (也就是最大值) 是否要刪除即可解題。

### stack

建議若能不用 stack 就不用，因為 stack 常數大。

#### 消除元素

若**可證明刪除元素的順序不影響答案**，就可以用 stack 的概念 $O(n)$ 從頭到尾看一遍，即可解題。

#### 單調堆疊

若 stack 維護的是單調的項目，這就是單調堆疊。

##### 例題：CSES Advertisement

題目敘述：給定一些有高度 $h_i$ 的圍牆，請找出一塊最大的長方形貼廣告。

解法：
1. 發現利用**貪心**，一個廣告一定會貼齊地面與一個高 $h_i$ 的圍牆，並盡可能往左右擴張。
2. 可以枚舉此圍牆，並計算此廣告**至多可以往右與往左延伸至何處**。
3. 此計算即是基礎單調堆疊題目，即可解題。

### deque

## 序列容器

### list 

### array

### vector

## 關聯容器

關聯容器常常以 `iterator` 的形式回傳與使用，所以必須認識一些特殊的 `iterator` 操作。

1. `*` 取值，可以寫 `*it` 取得 `it` 指向的值。
2. `->` 存取成員，可以寫 `it -> first` 取得 `set<pair<int, int>>::iterator` 中的前項。
3. `++it | --it |` 移動指標。
4. `prev(it) | next(it)` 取得前一個 / 後一個指標。
5. `rbegin()` 取得反向指標，也就是 `prev(end())`。請注意這個指標與一般指標的資料型態不同 `(::iterator | ::reverse_iterator)`，因此不能互相比較。

### set 和 multiset

#### 函式

`insert(x)` 插入 $x$。注意會回傳 `pair`，`.first` 是插入後的位置，`.second` 是檢查是否是第一個加入的。

`erase(x)` 移除 $x$。在 `multiset` 中若寫 `erase(1)` 會移除所有結構中的 $1$，因此要使用 `erase(myMulti.find(1))`。注意會回傳下一個 `iterator`。 

#### 由大到小排序

使用 `set<int, greater<int>> mySet` 以及 `multiset<int, greater<int>> myMultiset` 即可使內容物由大到小排序。

#### lower_bound / upper_bound

請使用 `mySet.lower_bound()`。請注意，這種 `iterator` 無法使用 `operator -`。

若資料結構是 `pair`，則尋找時的配對是先確認 `.first` 的大小。再看 `.second`。

### map

### unordered container

### priority\_queue

### 字串 Hash

使用字串 hash 可以快速以特定數字來代替字串，進而加速程式，可以做到 $O(1)$ 求出 hash。注意 hash value 無法回推字串。

```c++
struct HashString {
    static const long long m = 1e9 + 7;
    static const long long b = 9973;

    vector<long long> pow = {1};
    vector<long long> hashTable;

    HashString(const string &s) : hashTable(s.size() + 1) {
        while (pow.size() <= s.size()) pow.emplace_back(pow.back() * b % m);

        hashTable[0] = 0;
        for (int i = 0; i < s.size(); i++) {
            hashTable[i + 1] = (hashTable[i] * b % m + (s[i] - 'a')) % m;
        }
    }

    long long getHash(int st, int ed) {
        long long raw = (hashTable[ed + 1] - (hashTable[st] * pow[ed - st + 1]) % m);
        return ((raw % m) + m) % m;
    }
};
```

## 併查集 DSU

### 最小生成樹 MST

最小生成樹使用 $Kruskal's\ algorithm$，並使用 $DSU$ 判斷一條邊可否加入目前的樹。請至**演算法**查看。

## 稀疏表 Sparse Table

稀疏表是以倍增建構的表。一張表的 dp 定義如下：

$dp[i][j] :=$ 長度為 $2^i$，且從 $j$ 開始的此區間 $[j, j + 2^i)$ 運算的答案。


稀疏表建構為 $O(n \log n)$ ，查詢有兩種：

1. $O(1)$ 查詢可滿足 **運算項目重疊，答案仍相同** 的運算式。如 $max\ min\ gcd\ lcm\ or\ and$
2. $O(\log n)$ 查詢不滿足上述條件的運算式。

### 模板

```c++
template<typename T>
class BinaryLifting {
private:
    int n;
    int h;
    vector<vector<T>> table;

public:
    int oper(T a, T b) {
        return a > b ? a : b;
    }
    BinaryLifting (typename vector<T>::iterator _begin, typename vector<T>::iterator _end) {
        assert(_begin != _end);

        n = _end - _begin;
        h = __lg(n);

        table.assign(h + 1, vector<T>(n));
        table[0].assign(_begin, _end);

        for (int i = 1, len = 1; i <= h; i++, len <<= 1) {
            for (int j = 0; j + len * 2 <= n; j++) {
                table[i][j] = oper(table[i - 1][j], table[i - 1][j + len]);
            }
        }
    }

    T joint_search(int l, int r) {
        int len = __lg(r - l);

        return oper(table[len][l], table[len][r - (1 << len)]);
    }

    T disjoint_search(int l, int r) {
        int len = __lg(r - l);

        T ret = 0;

        for (; len >= 0; len--) {
            if (l + (1 << len) <= r) {
                ret = oper(ret, table[len][l]);
                l += (1 << len);
            }
        }
        
        return ret;
    }
};

```

### 稀疏表上二分搜

如果硬套二分搜，時間複雜度會多一個 $\log n$，因此要善用 $ST$ 的結構。由於 $ST$ 表上的長度都是 $2^n$，因此可以順著二的次方搜尋。

<!-- $$
H := \text{The biggest H which can let } 2^H \le \text{upper_bound}
$$ -->


## 樹狀陣列 BIT

$BIT$ 可計算**動態改變的前綴和**。下圖是 $BIT$ 儲存資料的方式。每個 $index$ 都是 $2^k$ 的區間。

```
---------------08---------------        
-------04-------                -------12-------
---02---        ---06---        ---10---
-01-    -03-    -05-    -07-    -09-    -11-    -13-

```


### 模板

```c++
template<typename T>
class BIT {
private:
    int n;
    vector<T> b;

public:
    BIT(int _n) : n(_n), b(_n + 1, 0) {};

    // 更新位於 x 的值 (加上 v)
    void upd(int x, T v) {
        for (; x <= n; x += x & -x) {
            b[x] += v;
        }
    }

    // 計算 1 ~ x 的前綴和
    T sum(int x) {
        T res = 0;
        for (; x; x -= x & -x) {
            res += b[x];
        }
        return res;
    }

    // 求第 k 小
    T kth(T k) {
        int h = __lg(n) + 1;
        int curr = 0;

        for (int i = h; i >= 0; i--) {
            if (curr + (1 << i) <= n && b[curr + (1 << i)] < k) {
                k -= b[curr + (1 << i)];
                curr += (1 << i);
            }
        }

        return curr + 1;
    }
};
```

### 逆序數對

若有數列 $\langle a_n \rangle$ 可以想像成：每次固定左界 $a_i$，去計算右邊有幾個數 $<a_i$。於是可以從**右到左移動左界**，$BIT$ 可以維護 $cnt[i] := i$ **出現幾次**，計算 $\sum_{j=i + 1}^{n} cnt[j]$，也就是**單點修改，區間查詢**。

通常遇到需要 **交換**，很大機率是 $BIT$。

#### 例題：`ABC441E` A \> B substring (還是你)

題目敘述：請求出 $\langle S_n\rangle \in [A, B, C]$ 如 $ABCAB$ 中，所有滿足：$A$ 個數 $>$ B 個數 的子字串 $(substring)$ 個數。

解法：將 $\langle S_n \rangle$ 中，$A := 1, B := -1, C := 0$ 去做差分，讓查詢 $pre[r] - pre[l - 1]$ 時的答案就是 A 與 B 個數差。可以發現，其實答案所求就是在**固定左界 $l$ 時，去求右邊有幾個 $pre[r] > pre[l]$**，於是即可以 $BIT$ 求解。

### 前綴最大最小值

$BIT$ 可改運算式為**紀錄最大或最小值**，就可以 $O(\log n)$ 求出前綴最大或最小值。

#### 例題：AEC dp Q Flowers

題目敘述：給你一些花與美麗度，現在要抽出一些花，使剩下的花高度可以遞增。請求出最大的美麗度。

解法：
1. 發現是 $LIS$，可想到 `dp[i][j] := 選到第 i 朵花，且目前遞增花的最後一個高 j，這時美麗度最好可以是多少`。
2. 可列出轉移式：
$$
dp[i][h_i] = \max_{1 \le k < n}
\begin{cases}
a[i] +  dp[i - 1][k] & \text{if } h_i \ge k\\
dp[i - 1][h_i] & \text{if } h_i \le k
\end{cases}
$$
3. 發現會超時，瓶頸在於求 $\max$ 的 $O(n)$。
4. 觀察轉移式，會發現要求的 $\max$ 都是**前綴最大值**，因此可以使用 $BIT$ 優化為 $O(\log n)$ 查詢。

### 區間數字種類

若要計算每個區間有幾種數字，可以使用離線演算法紀錄每個詢問的左界與右界。計算方式為：

1. 左移左界，將新加入的此數字標示為**最左邊第一次出現**。
2. 如果之前出現過此數，則取消之前那數的標記。
3. 處理所有左界在此的詢問，則答案變為：$\sum$ 所有數字在 右界 $r$ 左邊且被標記為**最左邊第一次出現**的個數。
4. 發現上述計算即是前綴和，使用 $BIT$ 解決。

#### 程式碼：

```c++
for (int l = n; l > 0; l--) {
    // 更新最先出現的位置
    bits.upd(l, 1);

    // 如果出現過，移除之前的位置
    if (lstPos.count(a[l]) != 0) {
        bits.upd(lstPos[a[l]], -1);
    }

    // 設定為現在的位置
    lstPos[a[l]] = l;

    // 均攤處理左界在 l 的詢問
    for (auto [r, index] : questions[l]) {
        ans[index] = bits.sum(r);
    }

    cerr << l << '\n';
}
```

### BIT 二分搜

觀察 $BIT$ 的儲存結構，可以推出二分搜其實就是：

1. 設定要走 $s = 2^k$ 步與下界 $l$。
2. 如果可以走 $s$ 步，那就將 $l + s$，如果不行就不移動下界。
3. 將 $s \div 2$，繼續下一個循環。

## 線段樹

### 模板

請注意，使用前須定義 `op(融合子樹1, 融合子樹2)` 與單位元素 `e()`。且此模板為 `0-based`。

```c++
// 0-based
template<class T, T (*op)(T, T), T (*e)()>
class SegTree {
private:
    int n;
    vector<T> node;

    void setCore(int L, int R, int id, int p, T &x) {
        if (L + 1 == R) { node[id] = x; return; }

        int mid = (L + R) / 2;

        if (p < mid)    setCore(L, mid, id * 2, p, x);
        else            setCore(mid, R, id * 2 + 1, p, x);

        node[id] = op(node[id * 2], node[id * 2 + 1]);
    }

    T getCore(int L, int R, int id, int l, int r) {
        // 不包含，回傳單位元素
        if (r <= L || R <= l) return e();
        // 完全包含，回傳 node
        if (l <= L && R <= r) return node[id];

        int mid = (L + R) / 2;
        return op(
            getCore(L, mid, id * 2, l, r),
            getCore(mid, R, id * 2 + 1, l, r)
        );
    }

public:
    SegTree (int _n) {
        n = 1;
        while (n < _n) n <<= 1;
        node.assign(2 * n, e());
        // 必須開 2^(x + 1) (min x s.t. 2^x > n)
    }

    void set(int p, T x) {
        setCore(0, n, 1, p, x);
    }

    // [l, r)
    T get(int l, int r) {
        return getCore(0, n, 1, l, r);
    }
};
```

#### 例題：CSES Prefix Sum Queries

題目敘述：給數列與兩種詢問：

1. 更改位於 $k$ 的值為 $u$。
2. 輸出區間 $[l, r]$ 的最大前綴和。

解法：發現每次融合時，其實只有兩種情況：

1. 最大前綴和就是左子樹的最大前綴和。
2. 最大前綴和橫跨左右，是左子樹總和 + 右子樹最大前綴和。

於是儲存資料為 `{maxPrefix, sum}`，即可解出此題。

請注意，由於**此題可以不選任何項目**，因此初始化與更動時，最大前綴和應是 **$\max \{0, a_i\}$。**

### 

## pbds

$pbds$ 是 $STL$ 內建好的樹，可以支援 $O(\log n)$ 找第 $k$ 小、多少元素 $< x$，插入與刪除。但注意並不是所有 OJ 皆支援。

### 寫法
```c++
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = 
    tree<T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

Tree<int> pbds;
```

- `insert()` 加入資料進入 $pbds$。
- `erase(x)` 移除第 $x$ 小的項目。
- `find_by_order(x)` 回傳第 $x$ 小的指標。
- `order_of_key(x)` 回傳 $x$ 所在的位置，也代表有多少項目 $< x$。

請注意，**第 $k$ 小均已 $k = 0$ 代表最小**，不像是 $BIT$ 或二分搜以第 $1$ 小 代表最小。

請注意，$pbds$ 跟 $set$ 一樣會去重，若要做到存取多個相同項目請 `insert({東西，id})`。

## trie