/*
Date: 2026-10-17

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

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n, m, s, t; cin >> n >> m >> s >> t;

    vector<tuple<int, int, ll>>e;
    for (int i = 0; i < m; i++)
    {
        int u, v; ll w; cin >> u >> v >> w;
        e.push_back({u, v, w});
    }

    vector<vector<ll>> dis(n + 1, vector<ll>(n + 1, 1e18));
    dis[s][0] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int depth = 0; depth < n; depth++)
        {
            for (auto [u, v, w] : e)
            {
                if (dis[v][depth + 1] > dis[u][depth] + w + depth) dis[v][depth + 1] = dis[u][depth] + w + depth;
            }
        }
    }

    cout << *min_element(dis[t].begin(), dis[t].end());
}