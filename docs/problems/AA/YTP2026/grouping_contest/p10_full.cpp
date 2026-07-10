// Date: 2026-05-24
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
    
    int n, m; cin >> n >> m;

    vector<int> color(n + 1); for (int i = 1; i <= n; i++) cin >> color[i];

    vector<vector<int>> e(n + 1);
    vector<array<int, 2>> edge(m); for (int i = 0; i < m; i++) 
    {
        int u, v;
        cin >> u >> v;

        edge[i] = {u, v};

        e[u].push_back(v);
        e[v].push_back(u);
    }

    vector<unordered_map<int, int>> cnt_color(n + 1);
    for (auto [u, v] : edge)
    {
        cnt_color[u][color[v]]++;
        cnt_color[v][color[u]]++;
    }

    ll ans = 0;
    for (auto [u, v] : edge)
    {
        // same color -> no
        if (color[u] == color[v]) continue;

        int cnt_u_side = e[u].size() - cnt_color[u][color[u]] - cnt_color[u][color[v]];
        int cnt_v_side = e[v].size() - cnt_color[v][color[u]] - cnt_color[v][color[v]];

        ll cnt_same_color_pair = 0;
        if (cnt_color[u].size() > cnt_color[v].size()) swap(u, v);
        
        for (auto [the_color, cnt] : cnt_color[u])
        {
            if (the_color == color[u] || the_color == color[v]) continue;
            cnt_same_color_pair += 1ll * cnt_color[u][the_color] * cnt_color[v][the_color];
        }

        ans += 1ll * (cnt_u_side * cnt_v_side - cnt_same_color_pair) * 2;
    }

    cout << ans;
}