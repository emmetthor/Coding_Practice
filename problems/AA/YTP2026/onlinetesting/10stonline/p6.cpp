/*
Date: 2026-07-05

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
    
    const int MAX_NM = 1600 + 5;
    const ll LL_INF = 1e18;

    int n, m; cin >> n >> m;

    vector<string> mp(n + 1); for (int i = 1; i <= n; i++)
    {
        string s; cin >> s;
        mp[i] = ' ' + s;
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
    {
        if (mp[i][j] == '.')
        {
            
        }
        else dp[i][j] = 0;

        cerr << dp[i][j] << " \n"[j == m];
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
    {
        if (mp[i][j] == '.') ans += dp[i][j] - 1;
    }

    cout << ans;
}