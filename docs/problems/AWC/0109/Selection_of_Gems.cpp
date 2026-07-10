/*
Date: 2026-07-09

Tags: knapsack_problems
Independent: 5
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

    const ll LL_MAX = 10;

    ll n, c, k; cin >> n >> c >> k;

    struct Item
    {
        ll value, weight;
    };

    vector<Item> items(n + 1); for (int i = 1; i <= n; i++) cin >> items[i].value >> items[i].weight;

    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(k + 1, vector<ll>(c + 1, -LL_MAX)));

    dp[0][0][0] = 0;

    auto chmax = [](ll &x, ll v)
    {
        if (v > x) x = v;
    };

    for (ll i = 1; i <= n; i++)
    {
        auto [i_v, i_w] = items[i];

        for (ll j = 0; j <= min(k, i); j++)
        {
            for (ll w = 0; w <= c; w++)
            {
                chmax(dp[i][j][w], dp[i - 1][j][w]);

                if (j > 0 && w - i_w / 2 >= 0) chmax(dp[i][j][w], dp[i - 1][j - 1][w - i_w / 2] + i_v);

                if (w - i_w >= 0) chmax(dp[i][j][w], dp[i - 1][j][w - i_w] + i_v);

                cerr << dp[i][j][w] << " \n"[w == c];
            }
        }
    }

    ll ans = -LL_MAX;
    for (int w = 0; w <= c; w++) for (int use = 0; use <= k; use++) chmax(ans, dp[n][use][w]);

    cout << ans;
}