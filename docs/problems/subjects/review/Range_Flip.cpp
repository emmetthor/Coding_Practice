/*
Date: 2026-07-26

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

    const ll INF = 1e18;
    
    int n, k; cin >> n >> k;
    vector<array<ll, 2>> a(n + 1); for (int i = 1; i <= n; i++) cin >> a[i][0] >> a[i][1];

    vector<vector<ll>> dp(n + 1, vector<ll>(2 * k + 1, -INF));
    dp[0][0] = 0;

    auto chmax = [](ll &x, ll v)
    {
        if (v > x) x = v;
    };

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 2 * k; j++)
        {
            dp[i][j] = dp[i - 1][j] + a[i][j % 2];

            if (j - 1 >= 0)
                chmax(dp[i][j], dp[i - 1][j - 1] + a[i][j % 2]);
        }
    }

    ll ans = 0;
    for (int j = 0; j <= 2 * k; j++) chmax(ans, dp[n][j]);

    cout << ans;
}