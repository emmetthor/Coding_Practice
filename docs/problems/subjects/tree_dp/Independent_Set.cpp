/*
Date: 2026-07-15

Tags: tree_dp
Independent: 4
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

    vector<vector<int>> e(n + 1); for (int i = 0; i < n - 1; i++)
    {
        int a, b; cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    vector<array<ll, 2>> dp(n + 1, {-1, -1});
    auto dfs = [&](auto self, int x, int p, int color) -> ll
    {
        if (dp[x][color] != -1) return dp[x][color];
        ll &res = dp[x][color] = 1;
        for (auto y : e[x])
        {
            if (y == p) continue;

            if (color == 0) {
                res = (res * (self(self, y, x, 0) + self(self, y, x, 1)) % MOD) % MOD;
            }
            else
            {
                res = (res * self(self, y, x, 0)) % MOD;
            }
        }
        return res;
    };

    cout << (dfs(dfs, 1, 1, 0) + dfs(dfs, 1, 1, 1)) % MOD;
}