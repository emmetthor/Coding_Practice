/*
Date: 2026-07-09
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
    ll n, s, k; cin >> n >> s >> k;

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ll ai; cin >> ai;
        ans += ai;
    }

    ans += s;
    ans += k * n;

    cout << ans;
}