/*
Date: 2026-07-22

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

struct DSU
{
    int n;
    vector<int> p;
    vector<int> sz;

    DSU(int _n) : n(_n), p(_n), sz(_n)
    {
        for (int i = 0; i < n; i++)
        {
            p[i] = i;
            sz[i] = 1;
        }
    }

    int leader(int x)
    {
        return (p[x] == x ? x : p[x] = leader(p[x]));
    }

    bool merge(int x, int y)
    {
        x = leader(x); y = leader(y);

        if (x == y) return 0;

        if (sz[x] < sz[y]) swap(x, y); // sz[x] > sz[y]

        sz[x] += sz[y];
        p[y] = x;

        return 1;
    }
};

struct Edge
{
    int u, v;
    ll w;

    bool operator<(const Edge &b) const
    {
        return w < b.w;
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int t; cin >> t;

    auto solve = []() -> void
    {
        int n, m; ll k; cin >> n >> m >> k;

        vector<Edge> edge(m);
        int id = -1;
        ll close_diff = 1e18;
        for (int i = 0; i < m; i++) 
        {
            cin >> edge[i].u >> edge[i].v >> edge[i].w;
            if (close_diff > abs(edge[i].w - k))
            {
                id = i;
                close_diff = abs(edge[i].w - k);
            }
        }

        DSU dsu(n + 1);
        ll ans = 0;

        sort(edge.begin(), edge.end());

        for (int i = 0; i < m; i++)
        {
            auto [u, v, w] = edge[i];
            cerr << "trying " << u << ' ' << v << ' ' << w << '\n';
            if (dsu.merge(u, v) == 1)
            {
                cerr << "merged\n";
                ans += max(0ll, w - k);
            }
        }

        if (ans == 0) ans += close_diff;
        cout << ans << '\n';
    };

    while (t--) solve();
}