/*
Date: 2026-07-03

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
    
    int t; cin >> t;

    auto solve = []() -> void
    {
        int x; ll m; cin >> x >> m;
        
        int ans = 0;
        for (int y = 1; y <= min(m, 1ll * 2 * x); y++)
        {
            if (x != y && (x % (x ^ y) == 0 || y % (x ^ y) == 0)) ans++;
        }

        cout << ans << '\n';
    };

    while (t--) solve();
}