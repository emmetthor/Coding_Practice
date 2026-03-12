/*
Tags: DSU, LCA

解法：
看到依時間建邊 -> 以時間為權重建模
發現若一邊先建立且連接新點，對於新點這是最好的路 -> MST
要求路徑上的最大權重 -> max weight based LCA

失誤：
未發現可能不是連通圖
*/

#include <bits/stdc++.h>
#ifdef LOCAL
    bool Debug = 1;
#else
    bool Debug = 0;
#endif
#define cerr if (Debug) cerr
using namespace std;

/*
bulit MST
LCA search distance
*/

struct DSU {
    int n;
    vector<int> p, sz;

    DSU (int _n) : p(_n + 1), sz(_n + 1), n(_n) {
        for (int i = 0; i <= n; i++) {
            p[i] = i;
            sz[i] = 1;
        }
    }

    int leader(int x) { return x == p[x] ? x : p[x] = leader(p[x]); }

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

struct LCA {
    int n, h, root;
    vector<vector<int>> dp, val;
    vector<vector<pair<int, int>>> e;
    vector<int> dep;

    LCA (int _n, int _root, vector<vector<pair<int, int>>> _e) {
        n = _n;
        root = _n;
        h = __lg(n) + 1;
        e = _e;
        dp.resize(h + 1, vector<int>(n + 1, 0));
        dep.resize(n + 1, -1);
        val.resize(h + 1, vector<int>(n + 1, 0));
    }

    void build() {
        auto dfs = [&](auto self, int x, int lst, int d) -> void {
            dep[x] = d;
            dp[0][x] = lst;
            for (auto [y, w] : e[x]) {
                if (y == lst) continue;
                val[0][y] = w;
                self(self, y, x, d + 1);
            }
        };

        for (int i = 1; i <= n; i++) {
            if (dep[i] == -1) {
                dfs(dfs, i, i, 0);
            }
        }

        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = dp[i - 1][dp[i - 1][j]];
                val[i][j] = max(val[i - 1][j], val[i - 1][dp[i - 1][j]]);
            }
        }
    }

    int qq(int x, int y) {
        if (dep[x] < dep[y]) swap(x, y);

        int ans = 0;
        int step = dep[x] - dep[y];

        for (int i = 0; i <= h; i++) {
            if ((step >> i) & 1) {
                ans = max(ans, val[i][x]);
                x = dp[i][x];
            }
        }

        cerr << "# " << x << ' ' << y << '\n';
        if (x == y) return ans;

        for (int i = h; i >= 0; i--) {
            if (dp[i][x] != dp[i][y]) {
                ans = max({ans, val[i][x], val[i][y]});
                x = dp[i][x];
                y = dp[i][y];
            }
        }

        cerr << x << ' ' << y << '\n';

        if (dp[0][x] != dp[0][y]) return -1;
        ans = max({ans, val[0][x], val[0][y]});
        x = dp[0][x]; y = dp[0][y];

        return ans;
    }
};

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    
    int n, m, q; cin >> n >> m >> q;

    DSU dsu(n);

    vector<vector<pair<int, int>>> e(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;

        if (dsu.merge(u, v) == true) {
            e[u].emplace_back(v, i + 1);
            e[v].emplace_back(u, i + 1);
        }
    }

    LCA lca(n, 1, e);
    lca.build();

    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        cout << lca.qq(a, b) << '\n';
    }
}