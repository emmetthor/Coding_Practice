// Date: 2026-05-31
#include <bits/stdc++.h>
#include <iomanip>
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
        ll x1, y1, r1, x2, y2, r2; cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        ll dis2 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);

        ll mi = min(r1, r2), ma = max(r1, r2);
        if ((ma - mi) * (ma - mi) <= dis2 && (r1 + r2) * (r1 + r2) >= dis2) cout << "Yes\n";
        else cout << "No\n";
    };

    while (t--) solve();
}