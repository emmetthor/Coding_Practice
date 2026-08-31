/*
Date: 2026-08-29

Tags: math, greedy
Independent: 5
Understanding: 5
Implementation: 5
Recognition: 3
*/
#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
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
        cerr << "===\n";
        ll n, m; cin >> n >> m;
        vector<ll> a(n); for (auto &i : a) cin >> i;
        sort(a.begin(), a.end());

        vector<int> cnt(m + 1);
        for (auto i : a) cnt[i]++;
        ll sum = accumulate(a.begin(), a.end(), 0ll);

        int log_m = __lg(m);

        for (int k = 1; k <= log_m; k++)
        {
            ll desig = 0;
            for (int i = 1; i <= m; i++)
            {
                ll res = 0;
                ll limit = (1ll << (k)) * i;

                if (limit > m) continue;

                int lower = lower_bound(a.begin(), a.end(), limit) - a.begin();
                int upper = a.end() - upper_bound(a.begin(), a.end(), limit);
                int exact = n - lower - upper;

                res += 1ll * exact * (1 << k);
                res += 1ll * upper * ((1 << k) - 1);

                int lst = 0;
                for (int j = i; j <= limit; j += i)
                {
                    int tmp = lower_bound(a.begin(), a.end(), j) - a.begin();      
                    res += 1ll * (j / i - 1) * (tmp - lst);
                    cerr << tmp << '\n';
                    lst = tmp;
                }
                cerr << k << ' ' << i << ' ' << res << ' ' << limit << ' ' << lower << ' ' << exact << ' ' << upper << '\n';
                desig = max(desig, res);
            } 

            cout << desig << ' ';
        }
        for (int k = log_m + 1; k <= m; k++) cout << sum << ' ';
        cout << '\n';
    };

    while (t--) solve();
}