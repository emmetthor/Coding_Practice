/*
Date: 2026-07-14

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

    const ll LL_MAX = 1e18;
    
    int n; cin >> n;

    vector<ll> a(n); for (auto &i : a) cin >> i;

    vector<ll> prefix(n + 1);
    for (int i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + a[i - 1];
    auto sum = [&](int l, int r) -> ll
    {
        l++; r++;
        return prefix[r] - prefix[l - 1];
    };

    vector<vector<ll>> dp(n, vector<ll>(n, LL_MAX));
    // auto dfs = [&](auto self, int l, int r) -> ll
    // {
    //     if (l + 1 > r) return 0;
    //     if (l + 1 == r) return a[l] + a[r];

    //     if (dp[l][r] != -1) return dp[l][r];
    //     dp[l][r] = LL_MAX;

    //     for (int k = l; k < r; k++)
    //     {
    //         dp[l][r] = min(
    //             dp[l][r],
    //             self(self, l, k) + self(self, k + 1, r) + sum(l, r)
    //         );
    //     }

    //     return dp[l][r];
    // };

    for (int i = 0; i < n; i++) dp[i][i] = 0;

    for (int len = 1; len <= n; len++)
    {
        for (int l = 0; l + len < n; l++)
        {
            int r = l + len;

            for (int k = 0; k < r; k++)
            {
                dp[l][r] = min(
                    dp[l][r],
                    dp[l][k] + dp[k + 1][r] + sum(l, r)
                );
            }
        }
    }

    cout << dp[0][n - 1];
}