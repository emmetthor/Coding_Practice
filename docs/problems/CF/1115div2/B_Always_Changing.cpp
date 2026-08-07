/*
Date: 2026-08-06

Tags: stack, observation
Independent: 5
Understanding: 5
Implementation: 5
Recognition: 5

Mistakes: wrong_proof
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
        string s; cin >> s;

        string ans = "";
        int d[2] = {};
        for (int i = 0; i < n; i++)
        {
            if (ans.size() && ans.back() == s[i])
            {
                d[s[i] - '0']++;
            }
            else
            {
                ans += s[i];
            }
        }

        int d_other = max(d[0], d[1]) - min(d[0], d[1]);
        d_other -= d_other > 0;
        int d_type = d[0] > d[1] ? 1 : 0;

        cerr << d[0] << ' ' << d[1] << ' ' << ans << '\n';
        cerr << d_other << ' ' << d_type << '\n';

        int d_cnt = d[0] + d[1];
        if (d_other == 0)
        {
            // do nothing
        }
        else if (ans.size() % 2 == 0)
        {
            if (d_other > 1) d_cnt += n;
            else d_cnt += 1;
        }
        else if (ans[0] - '0' == d_type)
        {
            if (d_other <= 2) d_cnt += d_other;
            else d_cnt += n;
        }
        else
        {
            d_cnt += n;
        }

        cout << (d_cnt >= n ? -1 : d_cnt) << '\n';
    };

    while (t--) solve();
}