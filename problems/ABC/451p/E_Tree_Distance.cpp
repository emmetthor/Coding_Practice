// Date: 2026-04-05
// Tags: MST, Greedy
//
// 解法：
// 請見題解 https://atcoder.jp/contests/abc451/editorial/18116
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
    vector<int> p, sz;
    DSU(int _n) : p(_n), sz(_n) {
        for (int i = 0; i < _n; i++) {
            p[i] = i;
            sz[i] = 1;
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
    
    int n; cin >> n;

    DSU dsu(n + 1);

    vector<tuple<int, int, int>> edge;
    vector<vector<int>> weights(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            int w; cin >> w;
            edge.emplace_back(w, i, j);
            weights[i][j] = w;
            weights[j][i] = w;
        }
    }

    sort(edge.begin(), edge.end());

    vector<vector<pair<int, int>>> tree(n + 1);
    for (int i = 0; i < edge.size(); i++) {
        auto [w, u, v] = edge[i];
        
        if (dsu.merge(u, v)) {
            tree[u].emplace_back(v, w);
            tree[v].emplace_back(u, w);
        }
    }

    cerr << "what\n";

    bool valid = 1;
    auto dfs = [&](auto self, int x, int lst, int start, int length) -> void {
        cerr << lst << ' ' << x << '\n';
        if (weights[start][x] != length) {
            valid = 0;
            cerr << start << ' ' << x << ' ' << length << '\n';
        }

        for (auto [y, w] : tree[x]) {
            if (y == lst) continue;

            self(self, y, x, start, length + w);    
        }
    };

    for (int i = 1; i <= n; i++) dfs(dfs, i, -1, i, 0);

    cerr << "what\n";

    cout << (valid ? "Yes" : "No");
}