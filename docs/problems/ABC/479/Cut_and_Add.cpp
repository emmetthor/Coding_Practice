/*
Date: 2026-10-11

Tags: fenwick_tree, euler_tour_technique
Independent: 5
Understanding: 5
Implementation: 5
Recognition: 5
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

struct BIT
{
    int n;
    vector<ll> b;

    BIT(int _n) : n(_n), b(_n + 1) {};

    void update(int p, ll x)
    {
        for (; p <= n; p += p & -p)
        {
            b[p] += x;
        }
    }

    ll prefix(int p)
    {
        ll res = 0;
        for (; p >= 1; p -= p & -p)
        {
            res += b[p];
        }
        return res;
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n; cin >> n;
    vector<vector<int>> e(n + 1);
    vector<pair<int, int>> edge;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b; cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
        edge.push_back({a, b});
    }

    vector<int> in(n + 1), out(n + 1);
    int timer = 0;
    vector<int> sz(n + 1, 1);
    vector<int> depth(n + 1);
    
    auto dfs = [&](auto self, int x, int p, int d) -> void
    {
        in[x] = ++timer;
        depth[x] = d;
        for (auto y : e[x])
        {
            if (y == p) continue;

            self(self, y, x, d + 1);
            sz[x] += sz[y];
        }
        out[x] = timer;
    };
    dfs(dfs, 1, 1, 1);

    for (int i = 1; i <= n; i++) cerr << in[i] << ' '; cerr << '\n';
    for (int i = 1; i <= n; i++) cerr << out[i] << ' '; cerr << '\n';
    for (int i = 1; i <= n; i++) cerr << sz[i] << ' '; cerr << '\n';
    for (int i = 1; i <= n; i++) cerr << depth[i] << ' '; cerr << '\n';

    ll global_const = 0;
    BIT bit(n + 1);

    for (int i = 1; i <= n - 1; i++)
    {
        auto [u, v] = edge[i - 1];
        if (depth[u] > depth[v]) swap(u, v); // u parent, v son

        int son_size = sz[v];
        int parent_size = n - sz[v];
        if (son_size > parent_size)
        {
            bit.update(in[v], +i);
            bit.update(out[v] + 1, -i);
        }
        else
        {
            global_const += i;
            bit.update(in[v], -i);
            bit.update(out[v] + 1, +i);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << bit.prefix(in[i]) + global_const << " \n"[i == n];
    }
}