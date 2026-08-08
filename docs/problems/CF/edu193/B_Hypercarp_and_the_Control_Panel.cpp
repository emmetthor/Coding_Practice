/*
Date: 2026-08-07

Tags: observation, swap_linked_technique
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
        vector<int> a(n + 2); for (int i = 1; i <= n; i++) cin >> a[i];
        a[0] = a[n + 1] = -1;

        int res = 0;
        for (int i = 1, j = 1; i <= n; i = j)
        {
            while (j <= n && a[i] == a[j]) j++;
            res++;
        }

        cerr << res << '\n';

        int max_swap = 0;
        for (int i = 1; i + 1 <= n; i++)
        {
            int swap_gain = 0;
            if (a[i] == a[i - 1] && a[i] != a[i + 1] && a[i] != a[i + 2]) swap_gain++;
            if (a[i + 1] == a[i + 2] && a[i + 1] != a[i] && a[i + 1] != a[i - 1]) swap_gain++;
            max_swap = max(max_swap, swap_gain);
        }

        cout << res + max_swap << '\n';
    };

    while (t--) solve();
}