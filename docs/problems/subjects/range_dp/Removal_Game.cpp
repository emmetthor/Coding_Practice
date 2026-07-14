/*
Date: 2026-07-14

Tags: range_dp
Independent: 3
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
    
    int n; cin >> n;
    ll sum = 0;
    vector<ll> a(n + 1); for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
    vector<vector<bool>> visi(n + 1, vector<bool>(n + 1));

    auto dfs = [&](auto self, int l, int r) -> ll
    {
        if (l == r) return a[l];
        if (visi[l][r]) return dp[l][r];
        visi[l][r] = 1;

        dp[l][r] = max(a[l] - self(self, l + 1, r), a[r] - self(self, l, r - 1));

        return dp[l][r];
    };

    cout << (sum + dfs(dfs, 1, n)) / 2;
}