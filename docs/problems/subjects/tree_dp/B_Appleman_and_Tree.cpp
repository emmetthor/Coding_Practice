/*
Date: 2026-07-15

Tags: subtree_merge_dp
Independent: 2
Understanding: 5
Implementation: 5
Recognition: 5
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

    const ll MOD = 1e9 + 7;
    
    int n; cin >> n;

    vector<vector<int>> e(n); for (int i = 1; i < n; i++)
    {
        int v; cin >> v;
        e[i].push_back(v);
        e[v].push_back(i);
    }

    vector<int> color(n); for (int i = 0; i < n; i++) cin >> color[i];

    int init[2][2] = {
        {1, 0},
        {0, 1}
    };

    vector<array<ll, 2>> dp(n);
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = init[color[i]][0];
        dp[i][1] = init[color[i]][1];
    }

    auto dfs = [&](auto self, int x, int p) -> void
    {
        for (auto y : e[x])
        {
            if (y == p) continue;

            self(self, y, x);
            
            ll a = dp[x][0];
            ll b = dp[x][1];
            ll c = dp[y][0];
            ll d = dp[y][1];

            dp[x][0] = (a * ((c + d) % MOD)) % MOD;
            dp[x][1] = ((a * d) % MOD + (b * ((c + d) % MOD)) % MOD) % MOD;
        }
    };

    dfs(dfs, 0, 0);

    cout << dp[0][1];
}