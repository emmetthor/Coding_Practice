/*
Date: 2026-07-02

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

    vector<ll> t(n + 1); for (int i = 1; i <= n; i++) cin >> t[i];

    vector<array<int, 2>> power(m); for (auto &[a, b] : power) cin >> a >> b;

    unordered_map<int, ll> sig;

    for (auto [p, b] : power)
    {
        int add_l = p - b + 1, add_r = p + 1;
        int minus_l = p + 1, minus_r = p + b + 1;

        sig[add_l]++;
        sig[add_r]--;
        sig[minus_l]--;
        sig[minus_r]++;
    }

    // 現在是模擬線段的開始與結束
    for (int i = 0; i <= n; i++) cerr << sig[i] << " \n"[i == n];

    for (int i = -n - 5; i <= 2 * n + 5; i++) sig[i] += sig[i - 1];
    // 現在是模擬訊號強弱的差分
    for (int i = 0; i <= n; i++) cerr << sig[i] << " \n"[i == n];

    for (int i = -n - 5; i <= 2 * n + 5; i++) sig[i] += sig[i - 1];
    // 現在是完整訊號
    for (int i = 0; i <= n; i++) cerr << sig[i] << " \n"[i == n];

    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (sig[i] <= t[i]) ans = max(ans, sig[i]);
    }

    cout << ans;
}