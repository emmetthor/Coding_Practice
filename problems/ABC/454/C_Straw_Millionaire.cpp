// Date: 2026-04-18
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
    vector<vector<int>> e(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        e[u].emplace_back(v);
    }

    vector<bool> visi(n + 1);

    auto dfs = [&](auto self, int x) -> void {
        if (visi[x]) return;
        visi[x] = 1;
        for (auto y : e[x]) self(self, y);
    }; dfs(dfs, 1);

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += visi[i];
    }

    cout << cnt;
}