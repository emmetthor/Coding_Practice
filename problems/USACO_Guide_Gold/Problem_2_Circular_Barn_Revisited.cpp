// Date: 2026-04-11
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

    const ll INF = 1e18;
    
    int n, k; cin >> n >> k;
    vector<ll> a(n);
    for (auto &i : a) cin >> i;
    
    // copy array
    for (int i = 0; i < n; i++) a.emplace_back(a[i]);

    // enumerate start
    for (int start = 0; start < n; start++) {
        vector<vector<ll>> dp(k + 1, vector<ll>(2 * n + 1, INF));
        // dp[i][j] := 用 i 個門且最後一門放在 j 這個位置時的最小答案
        dp[start][1] = 0;

        // enumerate door count
        for (int i = 2; i < k; i++) {
            for (int j = start + i; j < start + n; j++) {
                for (int x = start; x < j; x++) {
                    // dp[i][j] = min { dp[i - 1][k] + cost(j, k) }
                }
            }
        }
    }
}