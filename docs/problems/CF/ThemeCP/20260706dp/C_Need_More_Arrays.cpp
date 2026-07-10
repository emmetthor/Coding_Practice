/*
Date: 2026-07-06

Tags: dp, greedy
Independent: 4
Understanding: 5
Implementation: 5
Recognition: 4

Mistakes: wrong_idea
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
    
    int t; cin >> t;

    auto solve = []() -> void
    {
        int n; cin >> n;
        vector<int> a(n + 1); for (int i = 1; i <= n; i++) cin >> a[i];
        a[0] = a[1];

        vector<array<pair<int, int>, 2>> dp(n + 1);

        dp[0][0] = {1, a[0]};

        for (int i = 1; i <= n; i++)
        {
            dp[i][0].first = max(dp[i - 1][0].first + (a[i] - a[i - 1] > 1 ? 1 : 0), dp[i - 1][1].first + (a[i] - dp[i - 1][1].second > 1 ? 1 : 0));
            dp[i][0].second = a[i];
            
            if (i > 1)
            {
                dp[i][1].first = max(dp[i - 1][0].first, dp[i - 1][1].first);
                dp[i][1].second = (dp[i - 1][0].first == dp[i - 1][1].first ? min(dp[i - 1][0].second, dp[i - 1][1].second) : (dp[i - 1][0].first > dp[i  - 1][1].first ? dp[i - 1][0].second : dp[i - 1][1].second));
            }
        }

        cout << max(dp[n][0].first, dp[n][1].first) << '\n';
    };

    while (t--) solve();
}