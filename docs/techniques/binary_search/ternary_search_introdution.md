# Ternary Search 三分搜

## 這個 skill 解決什麼問題？

凸函數求頂點。

## 使用時機

凸函數。

## 核心想法

- 對斜率 $f'(x)$ 二分搜。
- 切三份，每次往比較小 / 大的地方走，最終就一定可以走到最小 / 大點。

## 實作

### 整數三分搜

由於是整數，因此可以使用 $f(x), f(x + 1)$ 比較來求斜率。

```cpp
int low = 0, hi = MAX;
while (low <= hi)
{
    int mid = (low + hi) / 2;
    if (f(mid) <= f(mid + 1))
        low = mid + 1;
    else
        hi = mid - 1;
}

cout << low;
```

### 浮點數三分搜

由於是小數，不太好求斜率，因此要使用正規三分搜寫法。

```cpp
double low = 0, hi = MAX;
for (int t = 0; t < 60; t++)
{
    double m1 = low + (hi - low) / 3;
    double m2 = hi - (hi - low) / 3;

    if (f(m1) <= f(m2))
        low = mid;
    else
        hi = mid;
}

cout << (low + hi) / 2;
```

## 常見錯誤

- 錯誤 1
- 錯誤 2

## 代表題目

| 題目 | 重點 |
| --- | --- |

## Agent Prompt

> 請你扮演這個 skill 的教練，按照本文的思考流程分析題目。
