/*
Date: 2026-07-16

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
    int n;
    const int LOG = 20;
    vector<vector<int>> e;
    vector<vector<int>> up;
    vector<int> depth;
    LCA(int _n) : n(_n), e(_n), up(_n, vector<int>(LOG)), depth(_n) {};

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

    int jump(int from, int d)
    {
        for(int k = 0; k < LOG; k++)
        {
            if ((d >> k) & 1)
            {
                from = up[from][k];
            }
        }

        return from;
    }

    int lca(int a, int b)
    {
        if (depth[a] > depth[b]) swap(a, b); // depth[a] < depth[b]
        b = jump(b, depth[b] - depth[a]);

        if (a == b) return a;

        for (int k = LOG - 1; k >= 0; k--)
        {
            if (up[a][k] != up[b][k])
            {
                a = up[a][k];
                b = up[b][k];
            }
        }

        return up[a][0];
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n, q; cin >> n >> q;

    LCA lca(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int a; cin >> a;
        lca.add_edge(a, i);
        lca.add_edge(i, a);
    }

    lca.build(1);

    while (q--)
    {
        int a, b; cin >> a >> b;
        cout << lca.lca(a, b) << '\n';
    }
}