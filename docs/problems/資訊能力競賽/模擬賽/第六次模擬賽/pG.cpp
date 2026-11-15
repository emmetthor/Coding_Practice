/*
Date: 2026-11-07

Tags: dijkstra (shortest_path)
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

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n, k, s, t; cin >> n >> k >> s >> t;

    if (s > t) swap(s, t);

    vector<map<int, ll>> station(k);
    vector<vector<int>> has(n + 1);

    for (int i = 0; i < k; i++)
    {
        int m; cin >> m;
        for (int j = 0; j < m; j++)
        {
            int u; ll p; cin >> u >> p;
            station[i][u] = p;
            has[u].push_back(i);
        }
    }

    vector<ll> dis(n + 1, 1e18);
    dis[s] = 0;
    queue<int> bfs;
    bfs.push(s);

    while (bfs.)
        for (auto j : has[i])
        {
            for (int r = 1; r <= n; r++)
            {
                if (station[j][r] == -1) continue;

                dis[r] = min(dis[r], dis[s] + max(station[j][i], station[j][r]));
            }
        }
    }

    for (int i = 1; i <= n; i++) cerr << dis[i] << ' ';
    cout << dis[t] << '\n';
}