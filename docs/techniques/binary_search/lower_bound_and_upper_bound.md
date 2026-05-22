# lower_bound() 與 upper_bound()

## 這個 skill 解決什麼問題？

和 `lower_bound()` 與 `upper_bound()` 有關的問題。

## 使用時機

- $>, \ge, =, \le, <, \in [l, r], \in[l, r), \in (l, r], \in (l, r)$ 的數字個數。
- 離散化。

## 核心想法

`lower_bound(k)` 會求出第一個 $x \ge k$ 的位址。 `upper_bound(k)` 則是求出第一個 $x > k$。

透過 `vector` 的 `std::random_access_iterator`，兩個函式的指標可以**相減求出距離**，也就是可以 `iter1 - iter2`。因而延伸出**可以計算特定項目個數**的能力。

## 常見模型

### 求出 $[l, r], [l, r), (l, r], (l, r)$ 中的數字個數

可以使用前綴和的方式思考，若把所有 $\le, < r$ 的數字個數減去 $\le, < l$ 的數字個數，就可以求出  $[l, r], [l, r), (l, r], (l, r)$ 中的數字個數。

以 $[l, r)$ 為例，則可以使用 `lower_bound(r) - lower_bound(l)` 求出所有 $\in [l, r)$ 的數字個數。

### 離散化

如果只需要知道**資料間的大小**關係，但是數字極大時，可以**使用離散化技巧，把數字壓成排名**。

利用 `lower_bound()` 與 `unique()`，便可以寫出離散化的模板。

```cpp
vector<int> ori(n);

// 先排序
sort(all(ori));
// 再用 unique 去重, erase 刪去多餘項目
ori.erase(unique(all(ori)), ori.end());

auto get = [&](int x) -> int
{
    // 利用 std::random_access_iterator 做距離相減，也就是名次
    return lower_bound(all(ori), x) - ori.begin() + 1;
};
```

## 常見錯誤

- 使用關聯容器時未使用內建 `lower_bound(), upper_bound()` 導致時間複雜度 $O(1) \rightarrow O(\log n)$ 而超時。

## 代表題目

| 題目 | 重點 |
| --- | --- |

## Agent Prompt

> 請你扮演這個 skill 的教練，按照本文的思考流程分析題目。
