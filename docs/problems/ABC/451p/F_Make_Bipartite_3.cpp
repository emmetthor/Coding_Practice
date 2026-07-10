// Date: 2026-04-05
// Tags: DSU
//
// 解法：
// 會發現最難處裡的其實是兩個連通塊的合併，因此聯想到 DSU
// 又會發現每次合併，若要改變某一連通塊的顏色，必須全部改，沒有其他方法省略，
// 根據 DSU 的啟發式合併，會發現如果把小的連通塊的所有點都並到大的連通塊去，那即是暴力換所有點的顏色，
// 時間複雜度仍然是 O(n log n)，因此可以過，剩下的就是複雜實作
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    bool debug_mode = 1;
#else
    bool debug_mode = 0;
#endif

using ll = long long;
#define cerr if(debug_mode) cerr

struct DSU {
    int n;
    vector<int> p, sz, white;
    DSU(int _n) : p(_n), sz(_n), white(_n) {
        for (int i = 0; i < _n; i++) {
            p[i] = i;
            sz[i] = 1;
            white[i] = 1;
        }
    }

    int leader(int x) {
        return (x == p[x] ? x : x = leader(p[x]));
    }

    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);

        if (x == y) return false;

        if (sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];
        p[y] = x;

        return true;
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n, m; cin >> n >> m;

    DSU dsu(n + 1);
    vector<set<int>> node_set(n + 1);

    // only the leader uses this color
    vector<int> color(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        node_set[i].insert(i);
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (ans == -1) {
            cout << -1 << '\n';
            continue;
        }

        int u, v; cin >> u >> v;

        int lu = dsu.leader(u);
        int lv = dsu.leader(v);

        if (lu == lv) {
            if (color[u] == color[v])
                ans = -1;
        } else {
            if (dsu.sz[lu] < dsu.sz[lv]) {
                swap(lu, lv);
                swap(u, v);
            }

            int small_white = dsu.white[lv];
            int big_white = dsu.white[lu];

            ans -= min(dsu.sz[lv] - small_white, small_white);
            ans -= min(dsu.sz[lu] - big_white, big_white);

            bool is_change_color = (color[u] == color[v] ? 1 : 0);

            for (auto node : node_set[lv]) {
                int changed_color = (is_change_color ? 1 - color[node] : color[node]);
                node_set[lu].insert(node);
                color[node] = changed_color;
            }

            int merge_white = big_white + (is_change_color ? dsu.sz[lv] - small_white : small_white);

            dsu.merge(lu, lv);

            ans += min(dsu.sz[dsu.leader(lu)] - merge_white, merge_white);
            dsu.white[dsu.leader(lu)] = merge_white;
        }

        cout << ans << '\n';
    }
}