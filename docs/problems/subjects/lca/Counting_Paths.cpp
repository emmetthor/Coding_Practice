/*
Date: 2026-07-17

Tags:
Independent:
Understanding:
Implementation:
Recognition:

Mistakes:
*/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    bool debug_mode = 1;
#else
    bool debug_mode = 0;
#endif

using ll = long long;
#define cerr if(debug_mode) cerr

struct LCA
{
    const int LOG = 20;
    int n;
    vector<vector<int>> e;
    vector<vector<int>> up;
    vector<int> depth;
    vector<int> diff;

    LCA(int _n) : n(_n), e(_n), up(_n, vector<int>(LOG)), depth(_n), diff(_n) {};

    void add_edge(int u, int v)
    {
        e[u].push_back(v);
    }

    void build(int root)
    {
        auto dfs = [&](auto self, int x, int p) -> void
        {
            up[x][0] = p;
            for (int k = 1; k < LOG; k++)
            {
                up[x][k] = up[up[x][k - 1]][k - 1];
            }

            for (auto y : e[x])
            {
                if (y == p) continue;
                depth[y] = depth[x] + 1;
                self(self, y, x);
            }
        };

        dfs(dfs, root, root);
    }

    int jump(int x, int d)
    {
        for (int k = 0; k < LOG; k++)
        {
            if ((d >> k) & 1) x = up[x][k];
        }
        return x;
    }

    int lca(int u, int v)
    {
        if (depth[u] > depth[v]) swap(u, v);
        v = jump(v, depth[v] - depth[u]);

        if (u == v) return u;

        for (int k = LOG - 1; k >= 0; k--)
        {
            if (up[u][k] != up[v][k])
            {
                u = up[u][k];
                v = up[v][k];
            }
        }

        return up[u][0];
    }
    
    vector<int> sum(int root)
    {
        auto dfs = [&](auto self, int x, int p) -> void
        {
            for (auto y : e[x])
            {
                if (y == p) continue;
                self(self, y, x);
                diff[x] += diff[y];
            }
        };

        dfs(dfs, root, root);

        return diff;
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n, m; cin >> n >> m;

    LCA lca(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v; cin >> u >> v;
        lca.add_edge(u, v);
        lca.add_edge(v, u);
    }

    lca.add_edge(1, 0);
    lca.add_edge(0, 1);

    lca.build(0);

    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        int _lca = lca.lca(u, v);
        cerr << u << " -> " << _lca << " -> " << v << '\n';

        lca.diff[u]++;
        lca.diff[v]++;
        lca.diff[_lca]--;
        lca.diff[lca.jump(_lca, 1)]--;
    }

    auto res = lca.sum(0);

    for (int i = 1; i <= n; i++) cout << res[i] << " \n"[i == n];
}