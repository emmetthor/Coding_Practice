/*
Date: 2026-07-02

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
        int n; cin >> n;
        vector<ll> a(n); for (auto &i : a) cin >> i;

        vector<ll> non_decreasing(n);
        int lst = a[0];
        for (int i = 0; i < n; i++)
        {
            if (a[i] < lst)
                non_decreasing[i] = lst;
            else
                non_decreasing[i] = a[i];
            lst = non_decreasing[i];
        }

        vector<ll> diff(n);
        ll max_diff = 0, sum_diff = 0;
        for (int i = 0; i < n; i++)
        {
            ll d = non_decreasing[i] - a[i];
            max_diff = max(max_diff, d);
            sum_diff += d;
        }

        cout << sum_diff + max_diff << '\n';
    };

    while (t--) solve();
}