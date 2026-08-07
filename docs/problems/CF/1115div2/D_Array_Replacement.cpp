/*
Date: 2026-08-07

Tags: difference
Independent: 3
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
        vector<ll> a(n); for (auto &i : a) cin >> i;
        vector<ll> d; for (int i = 1; i < n; i++) d.push_back(a[i] - a[i - 1]);
    
        for (int i = 0, j = 0; i < n - 1; i = j)
        {
            while (j < n - 1 && abs(d[i]) % 2 == abs(d[j]) % 2) j++;
            sort(d.begin() + i, d.begin() + j);
        }

        ll tmp = a[0];
        for (int i = 0; i < n - 1; i++)
        {
            cout << tmp << ' ';
            tmp += d[i];
            cerr << d[i] << ' ';
        }
        cerr << '\n';
        cout << tmp << '\n';
    };

    while (t--) solve();
}