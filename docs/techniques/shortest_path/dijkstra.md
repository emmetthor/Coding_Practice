# Dijkstra

## 這個 skill 解決什麼問題？

**求出所有點到某點最短路的演算法**。

## 使用時機

權重為正，可以 $O(n \log n)$ 的最短路題目。

## 核心想法

Dijkstra 是 BFS 的變種， SPFA 的優化，是 **BFS + 貪心 形成的演算法**。

> **[證明]** 每次 BFS 選擇距離出發點最近的點往下走必是最短路：
> 假設目前已經經過的點都是最近的距離。
> 若從現有**距離原點最近的點**繼續走，若權重都是正的，那麼這個點一定是最短路，因為其他點若要更新，要從**距離原點較遠的點經過權重往下走**，那肯定比這個點的距離還要遠。

## 實作

```cpp
struct Dijkstra {
    const int INF = 1e9;
    vector<vector<pair<int, int>>> e;
    vector<int> dis;
    vector<int> visi;
    int n;

    // 建構子初始化
    Dijkstra(int _n) {
        n = _n;
        e.resize(n);
        dis.resize(n);
        visi.resize(n);
    }

    // 新增正權邊
    void add_edge(int x, int y, int v) {
        e[x].push_back({y, v});
    }

    vector<int> shortest_path(int st) {
        // pool 紀錄目前距離原點最近的點
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pool;
        dis.assign(n, INF);
        visi.assign(n, 0);

        dis[st] = 0;
        pool.push({0, st});
        while (pool.size()) {
            auto [v, x] = pool.top();
            pool.pop();

            if (visi[x])
                continue;
            visi[x] = 1;
            // 能夠進來這裡的都是最短路

            for (auto [y, v2] : e[x]) {
                if (dis[y] > v + v2) {
                    dis[y] = v + v2;
                    pool.push({dis[y], y});
                }
            }
        }

        return dis;
    }
};
```

## 常見模型

### 滿足最佳子結構的另類最短路

Dijstra 不只能解最短路，如果運算式滿足**最佳子結構（即最好的答案一定是從他之前的答案推得的）** 就可以用 Dijkstra 解題。

滿足最佳子結構的運算如下：

1. $\max, \min$
2. $+, \times$
3. bitwise OR

不滿足最佳子結構的運算如下：

1. $\bmod$
2. $-, \div$
3. bitwise AND, XOR

### 第 k 短路

如果 `dis[]` 陣列不只存最短的路徑長，還**存前 k 短的所有路徑長**，就可以算出前 k 短的所有路徑長。

### 分層圖與圖論建模

### 多源最短路

如果**從不同起點同時開始搜尋最短路**，就是多源最短路的一種應用。

## 常見錯誤

- 未發現其實有**負權邊**。
- 未發現圖**不一定完全相連** 或 未發現是多源最短路。

## 代表題目

| 題目 | 重點 |
| --- | --- |
| AtCoder xxx | xxx |
| USACO xxx | xxx |

## Agent Prompt

> 請你扮演這個 skill 的教練，按照本文的思考流程分析題目。
