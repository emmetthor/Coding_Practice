/*
Date: 2026-07-26

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

    auto solve = []()
    {
        int n, x, s; cin >> n >> x >> s;
        string ss; cin >> ss;

        int cntA = 0; for (auto c : ss) cntA += (c == 'A');
        int low = 0, hi = cntA;
        while (low <= hi)
        {
            auto check = [&](int cntAtoI) -> 
            {

            }
        }

        vector<int> tables(x + 1);
        int it_empty = 0;
        int it_notfull = 0;
        int ans = 0;

        for (auto c : ss)
        {
            cerr << it_empty << ' ' << it_notfull << '\n';
            if (c == 'I')
            {
                if (it_empty < x)
                {
                    tables[it_empty]++;
                    ans++;
                    while (tables[it_notfull] == s) it_notfull++;
                    while (tables[it_empty] != 0) it_empty++;
                }
            }
            else if (c == 'E')
            {
                if (it_notfull < x && tables[it_notfull] > 0)
                {
                    tables[it_notfull]++;
                    ans++;
                    while (tables[it_notfull] == s) it_notfull++;
                    while (tables[it_empty] != 0) it_empty++;
                }
            }
        }

        cout << ans << '\n';
    };

    while (t--) solve();
}