/*
Date: 2026-06-13

Tags: 2d_map_implementation
Independent: 5
Understanding: 5
Implementation: 4
Recognition: 5

Mistakes: overcomplicated_solution
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
        ll a, b, x, y; cin >> a >> b >> x >> y;
        ll min_cost = min(a, b), max_cost = max(a, b);

        x = abs(x); y = abs(y);

        ll diag = min(x, y);
        ll rest_x = x - diag;
        ll rest_y = y - diag;

        cerr << diag << ' ' << rest_x << ' ' << rest_y << '\n';

        auto cost = [&](ll step, ll odd_cost, ll even_cost) -> ll
        {
            if (step % 2 == 0) return odd_cost * step / 2 + even_cost * step / 2;
            else return odd_cost * (step / 2 + 1) + even_cost * (step / 2);
        };

        ll diag_cost = 2 * min_cost * diag;

        if (max_cost / min_cost >= 3) // snake
        {
            if (rest_x)
            {
                if (a < b)
                    cout << diag_cost + cost(rest_x, min_cost, 3 * min_cost) << '\n';
                else
                    cout << diag_cost + cost(rest_x, 3 * min_cost, min_cost) << '\n';
            }
            else
            {
                if (a > b)
                    cout << diag_cost + cost(rest_y, min_cost, 3 * min_cost) << '\n';
                else
                    cout << diag_cost + cost(rest_y, 3 * min_cost, min_cost) << '\n';
            }
        }
        else // normal
        {
            cout << diag_cost + cost(rest_x, a, b) + cost(rest_y, b, a) << '\n';
        }
    };

    while (t--) solve();
}