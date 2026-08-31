/*
Date: 2026-08-29
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
        int n, m; cin >> n >> m;
        vector<ll> a(n); for (auto &i : a) cin >> i;
        sort(a.begin(), a.end());
        vector<int> cnt(m + 1);
        for (auto i : a) cnt[i]++;
        ll sum = accumulate(a.begin(), a.end(), 0ll);

        int log_m = __lg(m);

        for (int k = 1; k <= 1; k++)
        {
            ll get1 = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i] < (1 << k)) get1 += a[i];
                else if (a[i] > (1 << k)) get1 += (1 << k) - 1;
                else get1 += (1 << k);
            }

            ll half = 0;
            for (int i = 1; i <= m; i++)
            {
                ll total = cnt[i];
                ll check = i * 2;
                for (ll j = 0; j < k && check <= m; j++)
                {
                    total += cnt[check] * (1 << (j + 1));
                    check *= 2;
                }
                cerr << i << ' ' << total << '\n';
                half = max(half, total);
            }

            ll desig = 0;
            for (int i = 1; i <= m; i++)
            {
                ll res = a.end() - lower_bound(a.begin(), a.end(), i);
                if (2 * i <= m) res += cnt[2 * i];
                desig = max(desig, res);
                cerr << res << '\n';
            }

            cout << max({get1, half, desig}) << ' ';
        }
        // for (int k = log_m + 1; k <= m; k++) cout << sum << ' ';
        cout << '\n';
    };

    while (t--) solve();
}