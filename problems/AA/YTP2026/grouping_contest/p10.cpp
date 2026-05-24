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
    
    int n, m; cin >> n >> m;

    vector<int> color(n + 1); for (int i = 1; i <= n; i++) cin >> color[i];

    vector<vector<int>> e(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vector<bool> visi(n + 1);
    set<int> colors;
    auto dfs = [&](auto self, int x, int step) -> ll
    {
        if (visi[x]) return 0;
        if (colors.insert(color[x]).second == false) return 0;

        if (step >= 4)
        {
            colors.erase(color[x]);
            return 1;
        }

        visi[x] = 1;

        ll sum = 0;
        for (auto y : e[x])
        {
            sum += self(self, y, step + 1);
        }
        visi[x] = 0;
        colors.erase(color[x]);

        return sum;
    };

    ll sum = 0;
    for (int i = 1; i <= n; i++) sum += dfs(dfs, i, 1);

    cout << sum;
}