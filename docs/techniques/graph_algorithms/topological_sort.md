# Topological Sort 拓撲排序

## 核心知識點

若有 $u \rightarrow v$，則所有 $v$ 在 $u$ 前的序列就是拓撲排序。

**從葉節點開始，慢慢把父節點加入 `stack`** 就可以保證拓撲排序。

---

## 介紹

拓撲排序，是一種排序圖論節點的排序法。如果**一個序列的所有點，邊都指向他前面的點且沒有環，就是一種拓撲排序**。

實作拓撲排序時，可以使用 DFS 的特性，**在拜訪節點最後把此點加入排序**，就可以順利把最簡單、沒有順序關係的點排在前。

```cpp
vector<vector<int>> e(n, vector<int>(n));
vector<vector<bool>> visi(n, vector<bool>(visi));
vector<int> top_sort;

void dfs(int x)
{
    if (visi[x]) return;
    visi[x] = 1;

    for (auto y : e[x]) {
        dfs(y);
    }

    top_sort.emplace_back(x);

    for (int i = 0; i < n; i++)
        dfs(i);
}
```

---

## 常見模型

---

## 常見錯誤

- 未注意**圖不一定全部相連**。

---

## 代表題目

| 題目 | 重點 |
| --- | --- |

---

## Agent Prompt

> 請你扮演這個知識點的老師，按照本文的介紹詮釋這個知識點。
> 若本文知識點有誤，請點出錯誤的地方並予以修正。
