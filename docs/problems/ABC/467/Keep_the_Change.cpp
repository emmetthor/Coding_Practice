/*
Date: 2026-07-18

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
    
    int n; cin >> n;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ll a, b; cin >> a >> b;
        string s; cin >> s;
        if (s == "keep") ans += b - a;
    }

    cout << ans;
}