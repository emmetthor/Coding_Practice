/*
Date: 2026-10-24

Tags:
Independent:
Understanding:
Implementation:
Recognition:

Mistakes:
*/
#include <bits/stdc++.h>
#include <queue>
using namespace std;

#ifdef LOCAL
    bool debug_mode = 1;
#else
    bool debug_mode = 0;
#endif

using ll = long long;
#define cerr if(debug_mode) cerr

struct Dijkstra
{
    int n;
    vector<vector<pair<int, ll>>> e;
    vector<ll> dis;

    Dijkstra(int _n) : n(_n), e(_n), dis(_n, 1e18)
    {}

    void add_edge(int u, int v, ll w)
    {
        e[u].push_back({v, w});
    }

    vector<ll> shortest_path(int start)
    {
        dis[start] = 0;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pool;
        pool.push({dis[start], start});

        while (pool.size())
        {
            auto [v, x] = pool.top(); pool.pop();

            if (v > dis[x]) continue;

            for (auto [y, v2] : e[x])
            {
                if (dis[y] > v + v2)
                {
                    dis[y] = v + v2;
                    pool.push({dis[y], y});
                }
            }
        }

        return dis;
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n, m, s, t; cin >> n >> m >> s >> t;

    if (s == t)
    {
        cout << 0; return 0;
    }

    vector<vector<pair<int, ll>>> e(n + 1);
    Dijkstra dij_t(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v; ll w; cin >> u >> v >> w;
        dij_t.add_edge(v, u, w);
        e[u].push_back({v, w});
    }

    auto res_t = dij_t.shortest_path(t);

    vector<ll> worst(n + 1);
    for (int i = 1; i <= n; i++)
    {
        worst[i] = (res_t[i] == 1e18 ? 1e18 : 0);
        for (auto [j, v] : e[i])
        {
            if (res_t[j] == 1e18) worst[i] = 1e18;
            else worst[i] = max(worst[i], res_t[j] + v);
        }
    }

    for (int i = 1; i <= n; i++) cerr << worst[i] << '\n';

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pool;
    vector<ll> dis(n + 1, 1e18);
    dis[t] = 0;
    pool.push({dis[t], t});

    while (pool.size())
    {
        auto [v, x] = pool.top(); pool.pop();
        
        if (dis[x] < v) continue;

        for (auto [y, v2] : dij_t.e[x])
        {
            ll can = max(worst[y], v + v2);
            if (dis[y] > can)
            {
                dis[y] = can;
                pool.push({dis[y], y});
            }
        }
    }

    cout << (dis[s] == 1e18 ? -1 : dis[s]);
}