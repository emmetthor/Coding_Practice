/*
Date: 2026-07-14

Tags: range_dp
Independent: 4
Understanding: 5
Implementation: 5
Recognition: 5

Mistakes: constant
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

    const ll LL_MAX = 1e18;
    
    int n; cin >> n;

    vector<ll> b(n + 1); for (auto &i : b) cin >> i;

    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));

    // auto dfs = [&](auto self, int l, int r) -> ll
    // {
    //     if (l + 2 > r) return 0;
    //     if (l + 2 == r) return b[l] * b[l + 1] * b[l + 2];

    //     if (dp[l][r] != -1) return dp[l][r];
    //     dp[l][r] = LL_MAX;

    //     for (int k = l + 1; k < r; k++)
    //     {
    //         dp[l][r] = min(
    //             dp[l][r],
    //             self(self, l, k) + self(self, k, r) + b[l] * b[k] * b[r]
    //         );
    //     }

    //     cerr << "[ " << l << ", " << r << " ] = " << dp[l][r] << '\n';
    //     return dp[l][r];
    // };

    for (int len = 2; len <= n; len++)
    {
        for (int l = 0; l + len <= n; l++)
        {
            int r = l + len;
            dp[l][r] = LL_MAX;
            
            for (int k = l + 1; k < r; k++)
            {
                dp[l][r] = min(
                    dp[l][r],
                    dp[l][k] + dp[k][r] + b[l] * b[k] * b[r]
                );
            }
        }
    }

    cout << dp[0][n];
}