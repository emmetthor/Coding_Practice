// Date: 2026-05-23
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
    
    int n; cin >> n;

    vector<int> color(n + 1);
    for (int i = 1; i <= n; i++) cin >> color[i];

    vector<array<int, 2>> edge;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        
        if (color[u] != color[v]) edge.push_back({u, v});
    }

    vector<vector<int>> e(n + 1);
    for (int i = 0; i < edge.size(); i++) {
        auto [u, v] = edge[i];
        cerr << u << ' ' << v << '\n';
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vector<bool> visi(n + 1);
    auto dfs = [&](auto self, int x) -> int {
        if (visi[x]) return 0;
        visi[x] = 1;

        int sum = 1;
        for (auto y : e[x])
            sum += self(self, y);

        return sum;
    };

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll cnt = dfs(dfs, i);
        ans += (cnt - 1) * cnt / 2;
    }

    cout << ans;
}