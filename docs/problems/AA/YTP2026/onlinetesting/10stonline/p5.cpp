/*
Date: 2026-07-05

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
    
    int n; ll a, b, c, d; cin >> n >> a >> b >> c >> d;

    vector<ll> floor(n + 1); for (int i = 1; i <= n; i++) cin >> floor[i];
    floor[0] = 1;

    auto cost = [&](int from, int to) -> ll
    {
        ll x = floor[from], y = floor[to];
        return a + b * max(0ll, y - x) + c * max(0ll, x - y) + d * abs(y - x);
    };

    vector<vector<bool>> visi(n + 1, vector<bool>(n + 1));
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
    auto dfs = [&](auto self, int x, int y) -> ll
    {
        if (x == n)
            return 0;

        if (visi[x][y]) return dp[x][y];
        
        visi[x][y] = 1;

        ll &res = dp[x][y];

        res = min(
            self(self, x + 1, x) + cost(y, x + 1),
            self(self, x + 1, y) + cost(x, x + 1)
        );

        return res;
    };

    cout << dfs(dfs, 0, 0);
}