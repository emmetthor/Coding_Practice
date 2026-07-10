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
        int x, k; cin >> x >> k;
        
        if (x == 1)
        {
            if (k == 1)
            {
                cout << "NO\n";
                return;
            }
            if (k == 2)
            {
                cout << "YES\n";
                return;
            }
        }
        
        if (k > 1)
        {
            cout << "NO\n";
            return;
        }

        for (int i = 2; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                cout << "NO\n";
                return;
            }
        }

        cout << "YES\n";
    };

    while (t--) solve();
}