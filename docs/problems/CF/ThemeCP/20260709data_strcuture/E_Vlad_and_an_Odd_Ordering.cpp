/*
Date: 2026-07-09

Tags: greedy, equation_optimize
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

    auto solve = [&]() -> void
    {
        int n, k; cin >> n >> k;

        int in_group = -1;
        for (int i = 0; i < 60; i++)
        {
            ll group = (n + (1ll << (i))) / (1ll << (i + 1));

            cerr << "group " << i << " : " << group << '\n';

            if (k - group <= 0)
            {
                in_group = i;
                break;
            }

            k -= group;
        }

        cerr << in_group << '\n';

        cout << (1ll << in_group) + (k - 1) * (1ll << (in_group + 1)) << '\n';
    };

    while (t--) solve();
}