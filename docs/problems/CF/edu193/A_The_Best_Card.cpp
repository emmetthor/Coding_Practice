/*
Date: 2026-08-07

Tags: prime
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
        int n; cin >> n;
        for (int i = 2; i <= n; i++)
        {
            if ((n + 1) % i == 0)
            {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
    };

    while (t--) solve();
}