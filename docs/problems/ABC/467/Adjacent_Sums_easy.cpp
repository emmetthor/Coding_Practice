/*
Date: 2026-07-18

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
    
    int n, m; cin >> n >> m;

    vector<int> a(n), b(n - 1); for (auto &i : a) cin >> i; for (auto &i : b) cin >> i;
    vector<array<int, 2>> dp(n + 1);
    dp[0][0] = 0; dp[0][1] = 1;

    for (int i = 1; i < n; i++)
    {
        int sum = a[i - 1] + a[i];
        if (sum % m != b[i - 1])
        {
            dp[i][0] = dp[i - 1][1];
            dp[i][1] = dp[i - 1][0] + 1;
        }
        else
        {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1] + 1;
        }

        cerr << dp[i][0] << ' ' << dp[i][1] << '\n';
    }

    cout << min(dp[n - 1][0], dp[n - 1][1]);
}