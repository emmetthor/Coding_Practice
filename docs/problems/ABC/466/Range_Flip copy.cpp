/*
Date: 2026-07-11

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
    
    int n, k; cin >> n >> k;

    vector<pair<ll, ll>> card(n + 1); for (int i = 1; i <= n; i++) cin >> card[i].first >> card[i].second;

    auto cost = [&](int pos, int u) -> ll
    {
        return u % 2 == 0 ? card[pos].first : card[pos].second;
    };

    vector<vector<ll>> dp(2, vector<ll>(k + 1, -LL_MAX));
    auto chmax = [](ll &x, ll v) -> void
    {
        if (v > x) x = v;
    };

    dp[0][0] = card[1].first;
    if (k >= 1)
    {
        dp[1][1] = card[1].second;
    }

    for (int i = 2; i <= n; i++)
    {
        vector<vector<ll>> ndp(2, vector<ll>(k + 1, -LL_MAX));
        for (int cnt = 0; cnt <= k; cnt++)
        {
            if (dp[0][cnt] != -LL_MAX)
            {
                chmax(ndp[0][cnt], dp[0][cnt] + card[i].first);
                if (cnt + 1 <= k)
                {
                    chmax(ndp[1][cnt + 1], dp[0][cnt] + card[i].second);
                }
            }

            if (dp[1][cnt] != -LL_MAX)
            {
                chmax(ndp[1][cnt], dp[1][cnt] + card[i].second);
                chmax(ndp[0][cnt], dp[1][cnt] + card[i].first);
            }
        }
        dp.swap(ndp);
    }

    ll ans = -LL_MAX;
    for (int cnt = 0; cnt <= k; cnt++)
    {
        chmax(ans, dp[0][cnt]);
        chmax(ans, dp[1][cnt]);
    }

    cout << ans;
}