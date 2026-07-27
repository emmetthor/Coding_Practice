/*
Date: 2026-07-26

Tags: constructive
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

    auto solve = []()
    {
        int n, k; cin >> n >> k;

        if (k + 2 > n)
        {
            cout << -1 << '\n';
            return;
        }

        int m1 = k / 2, m2 = k - m1;

        cout << string(m1 + 1, '1') << string(m2 + 1, '0');
        for (int i = 0; i < (n - m1 - m2 - 2); i++) cout << (i % 2 == 0 ? 1 : 0);
        cout << '\n';
    };

    while (t--) solve();
}