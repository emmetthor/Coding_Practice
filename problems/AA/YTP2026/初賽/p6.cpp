/*
Date: 2026-07-07
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

    const int MAX_N = 100 + 5;
    
    int n, k, a, b; cin >> n >> k >> a >> b;
    vector<ll> nums(n); for (auto &i : nums) cin >> i;

    ll dp[MAX_N][MAX_N][2] = {}; // 第 i 項 j 的個數
    for (int i = 0; i < n; i++) dp[i][i][0] = 1;

    int it1 = 0, it2 = 1;
    for (int t = 0; t < k; t++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0)
                {
                    dp[i][j][it2] = (n - 1) * dp[i][j][it1] + dp[i + 1][j][it1];
                }
                else if (i == n - 1)
                {
                    dp[i][j][it2] = dp[i - 1][j][it1] + (n - 1) * dp[i][j][it1];
                }
                else
                {
                    dp[i][j][it2] = dp[i - 1][j][it1] + (n - 2) * dp[i][j][it1] + dp[i + 1][j][it1];
                }
            }
        }

        swap(it1, it2);
    }

    ll ans = 0;
    for (int i = a - 1; i <= b - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans += nums[i] * dp[i][j][it1];
            cerr << nums[i] << ' ' << dp[i][j][it1] << '\n';
        }
    }

    cout << ans;
}