/*
Date: 2026-07-31

Tags:
Independent:
Understanding:
Implementation:
Recognition:

Mistakes:
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

    const int MOD = 998244353;

    int t; cin >> t;

    auto solve = []()
    {
        int n; cin >> n;
        vector<vector<int>> e(n + 1);
        vector<int> p(n + 1);
        for (int i = 2; i <= n; i++)
        {
            int u; cin >> u;
            e[u].push_back(i);
            p[i] = u;
        }

        vector<vector<int>> depth_node(n + 1);
        vector<int> mark(n + 1);
        auto dfs = [&](auto self, int x, int d) -> void
        {
            depth_node[d].push_back(x);
            for (auto y : e[x])
            {
                self(self, y, d + 1);
                if (x != 1) mark[y] = -1;
            }
        };
        dfs(dfs, 1, 1);

        vector<int> res(n + 1);
        res[1] = 1;
        int sum = 1;
        for (int d = 1; d < n; d++)
        {
            int nsum = 0;
            for (auto x : depth_node[d + 1])
            {
                res[x] = (res[x] + sum) % MOD;
                if (mark[x] == -1) res[x] = (res[x] + MOD - res[p[x]]) % MOD; 
                nsum = (nsum + res[x]) % MO;
            }
            sum = nsum;
        } 
        int ans = 0;
        for (int i = 1; i <= n; i++) ans = (ans + res[i]) % MOD;
        cout << ans << '\n';
    };

    while (t--) solve();
}