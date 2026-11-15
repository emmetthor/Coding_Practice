/*
Date: 2026-11-14

Tags: dp
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

    const ll MOD = 1e9 + 7;
    
    int n, k; cin >> n >> k;
    
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1));
    dp[1][1] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            dp[i][j] = (dp[i][j] + (dp[i - 1][j] * (i - 1)) % MOD) % MOD;
            dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
        }
    }

    cout << dp[n][k];
}