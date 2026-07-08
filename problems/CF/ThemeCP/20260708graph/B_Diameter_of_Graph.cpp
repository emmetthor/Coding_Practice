/*
Date: 2026-07-08

Tags: greedy
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
    
    int t; cin >> t;

    auto solve = []() -> void
    {
        ll n, m, k; cin >> n >> m >> k;

        if (!(n - 1 <= m && m <= (n - 1) * n / 2))
        {
            cout << "NO\n"; return;
        }

        if (n == 1)
        {
            // d = 0
            cout << (0 < k - 1 ? "YES" : "NO") << '\n';
        }
        else if (m == (n - 1) * n / 2)
        {
            // d = 1
            cout << (1 < k - 1 ? "YES" : "NO") << '\n';
        }
        else {
            // d = 2
            cout << (2 < k - 1 ? "YES" : "NO") << '\n';
        }
    };

    while (t--) solve();
}