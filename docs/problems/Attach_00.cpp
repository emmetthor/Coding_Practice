/*
Date: 2026-07-13

Tags: greedy, structural_bounds
Independent: 5
Understanding: 5
Implementation: 5
Recognition: 5
*/
#include <bits/stdc++.h>
#include <string>
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
        ll k; cin >> k;

        for (int i = 0; i <= 100; i++)
        {
            ll num = k * (i + 1);

            string s = to_string(num);

            int max_len_0 = 0;
            int tmp = 0;
            for (auto c : s)
            {
                if (c == '0')
                {
                    tmp++;
                    max_len_0 = max(max_len_0, tmp);
                }
                else tmp = 0;
            }

            if (max_len_0 >= 2)
            {
                cout << num << '\n';
                return;
            }
        }
    };

    while(t--) solve();
}