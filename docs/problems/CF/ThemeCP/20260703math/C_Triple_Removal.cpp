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
        int n, q; cin >> n >> q;

        vector<int> a(n); for (auto &i : a) cin >> i;

        vector<int> prefix0(n + 1), prefix1(n + 1);
        for (int i = 1; i <= n; i++)
        {
            prefix0[i] += prefix0[i - 1] + (a[i - 1] == 0);
            prefix1[i] += prefix1[i - 1] + (a[i - 1] == 1);
        }

        vector<int> prefix_00_11_f(n + 1), prefix_00_11_b(n + 1); // if 00 or 11, then front number will be marked as 1
        for (int i = 1; i <= n; i++)
        {
            bool valid_f = (i < n && a[i - 1] == a[i]);
            bool valid_b = (i > 1 && a[i - 2] == a[i - 1]);
            prefix_00_11_f[i] = prefix_00_11_f[i - 1] + valid_f;
            prefix_00_11_b[i] = prefix_00_11_b[i - 1] + valid_b;
        }

        while (q--)
        {
            int l, r; cin >> l >> r;
            int cnt0 = prefix0[r] - prefix0[l - 1];
            int cnt1 = prefix1[r] - prefix1[l - 1];
            int cnt_00_11 = prefix_00_11_b[r] - prefix_00_11_f[l - 1];

            cerr << cnt0 << ' ' << cnt1 << ' ' << cnt_00_11 << '\n';

            if (!(cnt0 % 3 == 0 && cnt1 % 3 == 0))
            {
                cout << -1 << '\n';
                continue;
            }

            if (cnt_00_11)
            {
                cout << cnt0 / 3 + cnt1 / 3 << '\n';
            } else {
                cout << 1 + cnt0 / 3 + cnt1 / 3 << '\n';
            }
        }
    };

    while (t--) solve();
}