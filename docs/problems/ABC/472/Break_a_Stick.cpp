/*
Date: 2026-08-22
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
    vector<int> a(n); for (auto &i : a) cin >> i;

    ll ans = 1e18;
    for (int i = 0; i < n - 1; i++)
    {
        ll front = 0;
        ll back = 0;
        for (int j = 0; j <= i; j++) front += a[j];
        for (int j = i + 1; j < n; j++) back += a[j];

        cerr << front << ' ' << back << '\n';
        ans = min(ans, abs(front - back));
    }

    cout << ans;
}