// Date: 2026-03-22
// Tags: 二分圖, 塗色問題, 圖論建模
/*
解法：
會發現若要有盡可能多的 alternate path，就要使此點的每一邊都指出或指入，
這就類似塗色問題，
於是可以直接解塗色問題，答案就會是 max(顏色 1, 顏色 2)
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

    int t; cin >> t;

    auto solve = []() -> void {
        int n, m; cin >> n >> m;

        vector<vector<int>> e(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;
            e[u].emplace_back(v);
            e[v].emplace_back(u);
        }

        vector<bool> visi(n + 1);
        vector<int> color(n + 1);

        bool valid = 1;

        auto dfs = [&](auto self, int x, int c) -> pair<int, int> { // total size, color = 1 size
            if (visi[x]) {
                if (color[x] != 0 && color[x] != c) {
                    valid = 0;
                }
                return {0, 0};
            }
            visi[x] = 1;
            color[x] = c;

            int total_size = 1;
            int color1_size = (c == 1 ? 1 : 0);

            for (auto y : e[x]) {
                auto res = self(self, y, (c == 1 ? 2 : 1));
                total_size += res.first;
                color1_size += res.second;
            }

            cerr << x << ' ' << total_size << " | valid?=" << valid << '\n';

            return {total_size, color1_size};
        };

        ll ans = 0;

        for (int i = 1; i <= n; i++) {
            valid = 1;
            if (visi[i]) continue;

            auto [total_size, color1_size] = dfs(dfs, i, 0);

            if (!valid) continue;
            ans += max(total_size - color1_size, color1_size);
        }

        cout << ans << '\n';
    };

    while (t--) solve();
}