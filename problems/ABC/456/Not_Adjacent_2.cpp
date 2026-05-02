// Date: 2026-05-02
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

    const int MOD = 998244353;
    
    string s; cin >> s;
    int n = s.size();

    vector<int> dp(n + 1);
    int current_dp_sum = 0;
    int dp_type[26] = {};

    for (int i = 0; i < n; i++) {
        dp[i] += (((current_dp_sum - dp_type[s[i] - 'a']) % MOD + MOD) % MOD + 1) % MOD;

        current_dp_sum += dp[i];
        current_dp_sum %= MOD;

        dp_type[s[i] - 'a'] += dp[i];
        dp_type[s[i] - 'a'] %= MOD;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += dp[i];
        ans %= MOD;
    }

    cout << ans;
}