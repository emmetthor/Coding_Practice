/*
Date: 2026-07-26

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

    auto solve = []()
    {
        int n; cin >> n;
        vector<array<int, 4>> limits(n); for (auto &[l, r, u, v] : limits) cin >> l >> r >> u >> v;

        auto in_range = [](int p, int l, int r) -> bool
        {
            return l <= p && p <= r;
        };

        for (int len = n; len >= 0; len--)
        {
            cerr << "len=" << len << '\n';
            int choosing_rank = 1;
            for (auto [l, r, u, v] : limits)
            {
                int _r = len - u + 1, _l = len - v + 1;

                if (!(in_range(choosing_rank, l, r) || in_range(choosing_rank, _l, _r)))
                {
                    choosing_rank++;
                }
                else
                {
                    cerr << "in range: " << in_range(choosing_rank, l, r) << ' ' << in_range(choosing_rank, _l, _r) << '\n';
                }
            }

            if (choosing_rank >= len + 1)
            {
                cout << len << '\n';
                return;
            }
        }

        cout << 0 << '\n';
    };

    while (t--) solve();
}