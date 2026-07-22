# MST 最小生成樹

## 這個 skill 解決什麼問題？

**用最低成本建立一套完整連接網路**。

## 使用時機

一套完整連接網路，

## 介紹

最小生成樹（Minimum Spanning Tree）可由兩個演算法推出：

### Kruskal Algorithm

Kruskal 是典型的貪心演算法，可由以下偽程式碼實現：

```text

sort(所有邊)

for (所有邊)
{
    if (加入邊會產生環)
    {
        捨棄這條邊
    }
    else
    {
        加入這條邊
        DSU merge
    }
}

```

演算法的時間複雜度為 $O(E \log E)$。

::: details 貪心證明

TODO

:::

### Prim's Algorithm

Prim 與 Kruskal 關注的貪心不同。

| 演算法 | 貪心 |
| --- | --- |
| Kruskal | 整個圖的所有邊，取其最小邊加入 MST |
| Prim's | 目前 MST 的點中，向外延伸的所有邊，取其最小邊加入 MST |

因此，偽程式碼實現如下：

```text
選取任意一點 root

priority_queue<連接到此點的最小權重, 點> pq

vector<連接到此點的最小權重> dis

pq.push({0, root});

while (pq.size())
{
    auto [w, x] = pq.top()
    pq.pop()

    for (所有與 x 相鄰的點 y)
    {
        if (使用過) continue;

        if (w < dis[y])
        {
            dis[y] = w;
            pq.push({dis[y], y})
        }
    }
}
```

## 常見模型

### 連接網路最小花費

這種就是 MST 的經典題型。

### 最大生成樹

由於貪心證明一樣，因此只須把 Kruskal 演算法改成：「**整個圖的所有邊，取其最大邊加入 MST**」即可。

### 分群問題

若點對之間有距離，而題目對每一堆的距離有定義，如 $\min w(u, v) \quad (u, v \in \text{all points})$，就可以將問題轉換成：

::: tip 問題轉換

在 MST 中，切斷 $k$ 個邊，就是把整個圖分成 $k + 1$ 群。

:::

而通常，在做 Kruskal 的過程中，只要連通塊變成「目標」個，其實就是好的分群。

::: info 證明

TODO

:::

### MBST

Minimum Bottleneck Spanning Tree 是 MST 的一種延伸，他將原本要求的「最小邊權總和」改成「最小化最大邊權」。

這種題型還可以與 LCA 合併，變成：

::: tip 問題轉換

請求出一圖中，$Q$個詢問，詢問兩點間路徑間最大的邊長的最小值。

:::

可以先把圖做成 MBST，就可以用 LCA 解題了。

## 常見錯誤

TODO

## 代表題目

| 題目 | 重點 |
| --- | --- |

## Agent Prompt

> 請你扮演這個 skill 的教練，按照本文的思考流程分析題目。
