/*
Date: 2026-07-26

Tags: observation
Independent: 5
Understanding: 5
Implementation: 5
Recognition: 5

Mistakes: wrong_idea
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

        vector<int> a(n); for (auto &i : a) cin >> i;

        if (n % 2 == 1)
        {
            cout << "NO\n";
            return;
        }

        int low = 2e9, hi = 0;
        for (int i = 0; i < n; i += 2)
        {
            low = min(low, a[i]);
            hi = max(hi, a[i + 1]);
        }

        if (low - hi >= 2) cout << "YES\n";
        else cout << "NO\n";
    };

    while (t--) solve();
}