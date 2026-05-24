// Date: 2026-05-23
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

    const int INF = 1e9;
    
    int n; cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    
    vector<array<int, 3>> dp(n, {INF, INF, INF});
    
    dp[0][0] = 1;
    if ((a[0] >> 0) & 1) dp[0][1] = 0;
    if ((a[0] >> 1) & 1) dp[0][2] = 0;

    for (int i = 1; i < n; i++) {
        dp[i][0] = min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + 1;

        // 01
        if ((a[i] >> 0) & 1)
        {
            dp[i][1] = min({dp[i - 1][0],  dp[i - 1][2]});
        }
        
        // 10
        if ((a[i] >> 1) & 1)
        {
            dp[i][2] = min({dp[i - 1][0], dp[i - 1][1]});
        }
    }

    cout << min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
}