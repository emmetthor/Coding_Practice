/*
Date: 2026-08-09

Tags: greedy, observation
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
        int n, k; cin >> n >> k;
        string s; cin >> s;
        
        int give[2] = {};
        // give[0]: red -> blue / give[1]: blue -> red
        bool in_stack = 0;
        for (int i = 0; i < 2 * n; i++)
        {
            if (s[i] == '1') in_stack = 1;
            else
            {
                if (in_stack == 1) give[(i - 1) % 2]++;
                in_stack = 0;
            }
        }

        cerr << give[0] << ' ' << give[1] << '\n';

        if (s[2 * n - 1] == '1' && s[0] == '0') give[(2 * n - 1) % 2]++;

        int red_score = 0, blue_score = 0;
        for (int i = 0; i < 2 * n; i++)
        {
            if (s[i] == '0') continue;
            if (i % 2 == 0)
                red_score++;
            else
                blue_score++;
        }

        red_score -= give[0];
        blue_score += give[0];
        red_score += give[1];
        blue_score -= give[1];

        cout << blue_score << ' ' << red_score << '\n';
    };

    while (t--) solve();
}