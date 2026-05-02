// Date: 2026-05-02
#pragma GCC optimize("O3")
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

    const int MAX_N = 1e5 + 5, MAX_W = 10 + 5;
    
    int t; cin >> t;

    int visi[MAX_N][MAX_W] = {}, in_stack[MAX_N][MAX_W];
    vector<vector<int>> e(MAX_N);
    int lst = 0;

    auto solve = [&]() -> void {
        int n, m; cin >> n >> m;

        for (int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;
            e[u + lst].emplace_back(v);
            e[v + lst].emplace_back(u);
        }

        int w; cin >> w;
        vector<string> wk(n + 1);
        for (int i = 1; i <= n; i++) cin >> wk[i];

        bool found = 0;
        auto dfs = [&](auto self, int x, int day, int visi_mark) -> bool {
            cerr << "at " << x << '\n';
            int mod_day = day % w;
            if (visi[x + lst][mod_day] == visi_mark) {
                if (in_stack[x + lst][mod_day]) {
                    found = 1;
                    return 1;
                }
                else return 0;
            }
            if (day > 0) visi[x + lst][mod_day] = in_stack[x + lst][mod_day] = visi_mark;

            // stay still
            if (wk[x][mod_day] == 'o')
                if (self(self, x, day + 1, visi_mark))
                    return 1;

            // go other cities
            for (auto y : e[x + lst]) {
                if (wk[y][mod_day] == 'o')
                    if (self(self, y, day + 1, visi_mark))
                        return 1;
            }

            in_stack[x + lst][mod_day] = 0;

            return 0;
        };

        for (int i = 1; i <= n; i++) {
            if (wk[i][0] == 'o')
                dfs(dfs, i, 0, 1);
            for (auto y : e[i + lst])
                if (wk[y][0] == 'o') 
                    dfs(dfs, i, 0, 1);

            if (found) {
                cerr << "found from root city " << i << '\n';
                break;
            }
        }

        cout << (found ? "Yes\n" : "No\n");

        lst += n;
    };

    while (t--) solve();
}