/*
Date: 2026-07-29

Tags:
Independent:
Understanding:
Implementation:
Recognition:

Mistakes:
*/
#include <bits/stdc++.h>
#include <numeric>
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
    
    const int SZ = 1e6;
    int n, k; cin >> n >> k;

    vector<ll> a(n); for (auto &i : a) cin >> i;
    
    vector<ll> suffix(SZ + 1);
    for (auto i : a) suffix[i]++;

    for (int i = SZ - 1; i >= 0; i--) suffix[i] += suffix[i + 1];
    
    ll ans = 0;
    
    for (int i = k; i <= SZ; i++)
    {
        ll res = 0;
        for (int j = i; j <= SZ; j += i)
        {
            res += suffix[j];
        }
        
        ans = max(ans, 1ll * i * res);
    } 

    cout << ans;
}