/*
Date: 2026-08-29
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
    
    int t; cin >> t;

    auto solve = []()
    {
        int n; cin >> n;
        vector<int> a(n); for (auto &i : a) cin >> i;
        cout << gcd(a[0], a[n - 1]) << '\n';
    };

    while (t--) solve();
}