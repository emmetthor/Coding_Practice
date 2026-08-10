/*
Date: 2026-08-09

Tags: greedy, observation
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
        int a[3];
        for (int i = 0; i < 3; i++) cin >> a[i];
        sort(a, a + 3);

        cout << min(a[2] - a[0], a[1]) << '\n';
    };

    while (t--) solve();
}