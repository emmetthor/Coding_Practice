/*
Date: 2026-07-11

Tags: dp, parity
Independent: 4
Understanding: 5
Implementation: 5
Recognition: 5

Mistakes: off_by_one, debugging_slow, too_slow_solving
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
    
    int n, k; cin >> n >> k;

    vector<pair<ll, ll>> card(n + 1); for (int i = 1; i <= n; i++) cin >> card[i].first >> card[i].second;

    auto cost = [&](int pos, int u) -> ll
    {
        return u % 2 == 0 ? card[pos].first : card[pos].second;
    };

    vector<vector<ll>> dp(n + 1, vector<ll>(2 * k + 1, -LL_MAX));
    dp[0][0] = 0;

    auto chmax = [](ll &x, ll v) -> void
    {
        if (v > x) x = v;
    };

    for (int i = 1; i <= n; i++)
    {
        for (int u = 0; u <= 2 * k; u++)
        {
            chmax(dp[i][u], dp[i - 1][u] + cost(i, u));
            if (u >= 1) chmax(dp[i][u], dp[i - 1][u - 1] + cost(i, u));
        }
    }

    ll ans = -LL_MAX;
    for (int u = 0; u <= 2 * k; u++)
    {
        chmax(ans, dp[n][u]);
    }

    cout << ans;
}