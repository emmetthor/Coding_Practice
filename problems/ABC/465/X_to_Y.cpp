/*
Date: 2026-07-04

Tags: lca
Independent: 5
Understanding: 3
Implementation: 5
Recognition: 0

Mistakes: wrong_recognition
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

    const ll MAX_Y = 2e18;
    
    int t; cin >> t;

    auto solve = [&]() -> void
    {
        ll x, y, k; cin >> x >> y >> k;
        cerr << "=== " << x << ' ' << y << ' ' << k << " ===\n";
        
        int ans = 1e9;

        for (int i = 0; i < 60; i++)
        {
            ll low = x;
            ll hi = x;
            for (int j = 0; ; j++)
            {
                cerr << low << ' ' << hi << '\n';

                if (low <= y && y <= hi)
                {
                    cout << i + j << '\n';
                    return;
                }

                if (low >= y) break;
                if (hi >= y) break;

                if (low > (MAX_Y) / k) low = MAX_Y;
                else low = low * k;

                if (hi > (MAX_Y - k - 1ll) / k) hi = MAX_Y;
                else hi = hi * k + k - 1ll;
            }

            if (x == 0) break;

            x /= k;
        }

        cout << ans << '\n';
    };

    while (t--) solve();
}