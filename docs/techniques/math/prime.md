# 質數 Prime

## 核心知識點

**埃式篩法**和**質因數分解**非常重要！

---

## 介紹

### 埃式篩法

「**篩法**」就是篩選出質數的方法，而競程常用的篩法就是埃式篩法。

埃式篩法的實作方式如下：

```cpp
vector<bool> prime(SZ + 1, 1);
prime[0] = prime[1] = 0;

for (int i = 2; i * i <= SZ; i++) {
    if (prime[i] == 0) continue;
    for (int j = 2 * i; j <= SZ; j += i) prime[j] = 0;
}
```

其原理為：**枚舉所有質數，把這個質數的倍數都標記成合數**，那剩下的就是質數了。時間複雜度為 $O(n \sqrt n)$

> **[問題]** 為何質數 $i$ 只需枚舉 $1 \sim \sqrt N$ 就可以停下來？
>
> 可以透過反證法：
>
> > 若存在一個合數 $\sqrt N < m <  N$，則此合數必定可以表示成 $m = a \times b$ 滿足 $a \in \mathbb{N} \wedge b \in \mathbb{N}$。
> >
> > 透過埃式篩，可知這時的 $m$ 沒有一個 $\le \sqrt N$ 的因數，因為**這些因數都已經確認過了**。
> >
> > 所以 $\sqrt N < a, b$，故 $m > N$，產生矛盾。
> >
> > 因此命題為 $F$。

### 質因數分解

競程中有時會需要進行質因數分解，可以分為兩種形式：

#### 詢問少，數字大

若數字可以大到 $N \le 10^{12}$，可以使用類似埃式篩的想法，暴力將此數拆成所有質數相乘。時間複雜度為 $O(\sqrt N)$。

```cpp
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

#### 詢問多，數字小

若詢問達到 $Q \le 10^5$，但是數字卻 $N \le 10^7$，這時需要使用 Smallest Prime Factor (SPF)，來把每次操作的時間複雜度降到 $O(\log N)$。

##### SPF 原理

SPF 會記錄所有數的最小質因數，這樣在拆分一數 $N$ 時就可以 $N' = N \div spf[N]$ 後遞迴至 $N' = 1$。

以 $60$ 舉例，$60$ 會經歷以下步驟被質因數分解：

$$\begin{aligned} 60 &= 2 \times 30 \\ 30 &= 2 \times 15 \\ 15 &= 3 \times 5 \\ 5 &= 5 \times 1\# \end{aligned}$$

因此 $60 = 2^2 \cdot 3 \cdot 5$。

##### 實作

```cpp
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

> **[問題]** 為何時間複雜度會是 $O(\log N)$？
>
> 對於最差情況，也就是數字降低最慢的方式，就是當 $N = 2^k$ 時，每次都只能 $\div 2$。
>
> 這時所需除法次數就會是：$k = \log_2N$

---

## 常見模型

### 基礎知識應用

對，真的有題目就要直接找質數 / 質因數分解。

### 與 lcm 結合

lcm 在計算時取的數會是：所有數質因數分解後，**對於每個質數，取下「最大次方」並乘進 lcm result 裡**。因此通常會使用質因數分解來輔助解題。

---

## 常見錯誤

TODO

---

## 代表題目

TODO

---

## Agent Prompt

> 請你扮演這個知識點的老師，按照本文的介紹詮釋這個知識點。
> 若本文知識點有誤，請點出錯誤的地方並予以修正。
