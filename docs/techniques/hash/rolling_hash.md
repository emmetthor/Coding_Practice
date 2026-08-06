# 滾動雜湊 Rolling Hash

## 這個 skill 解決什麼問題？

需要 $O(1)$ 求出區間雜湊值的問題。

## 使用時機

字串配對。

## 核心想法

將字串看成 $B$ 進位，並用 $M$ 將數值壓縮到 $[0, M)$ 之間做雜湊。

## 介紹

Rolling Hash 透過「多項式雜湊」，將字串看成 $B$ 進位，再模 $M$ 做映射。

因此，一段字串 $s[l:r]$ 的雜湊值可以看成：

$$
\sum_{i = l}^{r} s[i] \times B^{i-l} \bmod M
$$

但是，每次用 $O(n)$ 計算太慢了，注意到公式中有 $\sum$，因此可以轉成前綴和的形式。

預處理：
$$
ht[i + 1] = ht[i] \times B + s[i]
$$

則一段字串 $s[l:r]$ 的雜湊值就是：
$$
ht[r + 1] - h[l] \times B^{r - l + 1}
$$

請記得取模與 `integer_overflow` 的問題。

## 實作

若是固定的字串，可寫成 `struct`：

```cpp
struct HashString
{
    int n;
    string s;
    ll m;
    ll b;
    vector<ll> pow;
    vector<ll> hash_table;

    HashString(string _s, ll _m = 1e9 + 7, ll _b = 114514)
    : n(_s.size()), s(_s), m(_m), b(_b), hash_table(_s.size() + 1)
    {
        int pp = 1;
        for (int i = 0; i <= n; i++)
        {
            pow.push_back(pp);
            pp = pp * b % m;
        }

        for (int i = 0; i < n; i++)
        {
            hash_table[i + 1] = (hash_table[i] * b % m + (s[i] - 'a' + 1)) % m;
        }
    }

    ll get(int l, int r)
    {
        return ((hash_table[r] - hash_table[l] * pow[r - l] % m) % m + m) % m;
    }
};
```

而另一種更活動的寫法是只寫一個雜湊值推導至下一個雜湊值的函式：

```cpp
auto next_hsh = [](ll hsh, char c, ll b = 114514, ll m = 1e9 + 7)
{
    return (hsh * b % m + (c - 'a' + 1)) % m;
};
```

## 常見模型

### Stack 中的 rolling hash

由於 rolling hash 是以前綴和的形式實作，因此與 `stack` 的適配性也很好，特別是 `next_hsh()` 的寫法。

通常若可把題目改成「**從右到左構造字串**」，就可以在跑 `stack` 的過程中順便維護 hash。

## 常見錯誤

## 代表題目

| 題目 | 重點 |
| --- | --- |
| USACO 2015 February Contest, Silver Problem 1. Censoring | stack 中的 rolling hash |

## Agent Prompt

> 請你扮演這個 skill 的教練，按照本文的思考流程分析題目。
