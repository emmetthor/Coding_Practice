/*
Date: 2026-07-07
*/
#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
using namespace std;

#ifdef LOCAL
    bool debug_mode = 1;
#else
    bool debug_mode = 0;
#endif

using ll = long long;
#define cerr if(debug_mode) cerr

struct DSU {
    vector<int> p, sz; /*p[i] := i 的祖先，sz[i]在 i 為樹根時代表大小*/

    DSU(int n) : p(n + 1), sz(n + 1) { /*建構子初始化*/
        for (int i = 0; i <= n; i++) {
            p[i] = i;
            sz[i] = 1;
        }
    }

    int leader(int x) { /*尋找 x 的樹根 + 路徑壓縮*/
        return x != p[x] ? p[x] = leader(p[x]) : x;
    }

    int size(int x) { /*求出 x 那組的大小*/
        return sz[leader(x)];
    }

    bool same(int x, int y) { /*判斷 x 跟 y 是否同組*/
        return leader(x) == leader(y);
    }

    void merge(int x, int y) { /*將 x, y 連在一起*/
        x = leader(x);
        y = leader(y);

        if (x == y)
            return;

        if (sz[x] < sz[y]) /*啟發式合併*/
            swap(x, y);

        sz[x] += sz[y];
        p[y] = x;
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    const int MAX_T = 500 + 5;
    
    int n, m, k, q; cin >> n >> m >> k >> q;

    set<pair<int, int>> remain_edge;
    vector<vector<int>> e(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
        remain_edge.insert({u, v});
    }

    vector<pair<int, int>> burn_tree(k);
    for (auto &[a, b] : burn_tree) cin >> b >> a;

    sort(burn_tree.begin(), burn_tree.end());

    vector<array<int, 2>> qq(q);
    for (auto &[a, b] : qq) cin >> a >> b;
    vector<int> ans(q, -1);

    vector<array<int, 3>> burned_edge;

    vector<bool> visi(n + 1);

    int iter = 0;
    queue<int> bfs;
    for (int t = 0; t < MAX_T; t++)
    {
        while (iter < k && burn_tree[iter].first == t)
        {
            bfs.push(burn_tree[iter++].second);
        }

        int sz = bfs.size();
        while (bfs.size() && sz--)
        {
            int x = bfs.front(); bfs.pop();

            if (visi[x]) continue;
            visi[x] = 1;

            for (auto y : e[x])
            {
                if (!visi[y])
                {
                    burned_edge.push_back({t, x, y});
                    bfs.push(y);
                }
            }
        }
    }

    sort(burned_edge.begin(), burned_edge.end(), greater<>());

    for (auto [t, u, v] : burned_edge)
    {
        remain_edge.erase({u, v});
        remain_edge.erase({v, u});
    }

    DSU dsu(n + 1);

    for (auto [a, b] : remain_edge)
    {
        cerr << "remain: " << a << ' ' << b << '\n';
        dsu.merge(a, b);
    }

    int iter2 = 0;
    for (int t = MAX_T; t >= 0; t--)
    {
        while (iter2 < burned_edge.size() && burned_edge[iter2][0] == t + 1)
        {
            dsu.merge(burned_edge[iter2][1], burned_edge[iter2][2]);
            iter2++;
        }

        for (int i = 0; i < q; i++)
        {
            auto [a, b] = qq[i];

            if (dsu.same(a, b)) ans[i] = max(ans[i], t);
        }
    }

    for (int i = 0; i < q; i++)
    {
        if (ans[i] == MAX_T) cout << -164253;
        else if (ans[i] == -1) cout << -1;
        else cout << ans[i];
        cout << '\n';
    }
}