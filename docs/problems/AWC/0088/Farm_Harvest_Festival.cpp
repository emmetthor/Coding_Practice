/*
Date: 2026-06-10

Tags: difference
Independent: 5
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
    
    int n, m; cin >> n >> m;
    vector<ll> harvest(n); for (auto &i : harvest) cin >> i;

    vector<int> diff(n + 1);
    for (int i = 0; i < m; i++)
    {
        int l, r; cin >> l >> r;
        l--; r--;
        diff[l]++;
        diff[r + 1]--;
    }
    for (int i = 1; i <= n; i++)
    {
        diff[i] += diff[i - 1];
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (diff[i] > 0) ans += harvest[i];
    }

    cout << ans;
}