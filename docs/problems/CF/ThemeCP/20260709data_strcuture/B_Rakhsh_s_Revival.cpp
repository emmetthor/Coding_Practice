/*
Date: 2026-07-09

Tags: greedy
Independent: 3
Understanding: 5
Implementation: 5
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
        int n, m, k; string s; cin >> n >> m >> k >> s;

        int ans = 0;
        int counter = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                counter++;

                if (counter == m)
                {
                    ans++;
                    for (int it = 0; it < k; it++)
                    {
                        s[min(n - 1, i + it)] = '1';
                    }

                    counter = 0;
                }
            }
            else counter = 0;
        }

        cerr << s << '\n';
        cout << ans << '\n';
    };

    while (t--) solve();
}