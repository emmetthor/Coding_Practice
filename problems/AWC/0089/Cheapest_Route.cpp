/*
Date: 2026-06-11

Tags:dijkstra, muiti_source
Independent: 5
Understanding: 5
Implementation: 5
Recognition: 5

Mistakes:template_not_familiar, reading_misunderstanding
*/
#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

#ifdef LOCAL
    bool debug_mode = 1;
#else
    bool debug_mode = 0;
#endif

using ll = long long;
#define cerr if(debug_mode) cerr

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    const ll INF = 1e18;
    
    int n, m, p; cin >> n >> m >> p;

    vector<ll> cost(n + 2); for (int i = 1; i <= n; i++) cin >> cost[i];

    vector<vector<pair<int, ll>>> e(n + 2);
    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        e[u].push_back({v, cost[u] * cost[v]});
        e[v].push_back({u, cost[u] * cost[v]});
    }

    using data = pair<ll, int>;
    priority_queue<data, vector<data>, greater<data>> pool;
    vector<ll> dis(n + 2, INF);

    for (int i = 0; i < p; i++)
    {
        int u; cin >> u;
        dis[u] = 0;
        pool.push({0, u});
    }

    while (pool.size())
    {
        auto [curr_weight, x] = pool.top(); pool.pop();

        for (auto [y, weight] : e[x])
        {
            if (dis[y] > curr_weight + weight)
            {
                dis[y] = curr_weight + weight;
                pool.push({dis[y], y});
            }
        }
    }

    cout << dis[1];
}