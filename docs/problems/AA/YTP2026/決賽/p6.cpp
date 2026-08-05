#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;

#define int long long

int n, m, k;
vector<vector<pair<int, int>>> e;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n >> m >> k;
    e.resize(n +1);
    for (int i = 0; i < m; i++) {
        int u, v, dan;
        cin >> u >> v >> dan;
        e[u].push_back({v, dan});
        e[v].push_back({u, dan});
    }

    int low = 0, hi = 1e9;
    while (low <= hi)
    {
        vector<int> vis(n + 1);
        int mid = (low + hi) / 2;
        auto dfs = [&](auto self, int x, int kk) -> void
        {
            if (vis[x]) return;
            vis[x] = 1;
            for (auto [y , w] : e[x])
            {
                if (w > mid)
                {
                    if (kk < k) self(self, y, kk + 1);
                    else continue;
                }
                self(self, y, kk);
            }
        };
        dfs(dfs, 1, 0);

        if (vis[n]) hi = mid - 1;
        else low = mid + 1;
    }

    cout << (low == 1e9 + 1 ? -1 : low);
}
