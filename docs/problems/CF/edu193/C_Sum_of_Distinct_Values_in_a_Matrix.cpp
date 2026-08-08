/*
Date: 2026-08-07

Tags: delayed_greedy
Independent: 3
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
        int n, m, x, y; cin >> n >> m >> x >> y;
        vector<int> a(x); for (auto &i : a) cin >> i;
        vector<int> b(y); for (auto &i : b) cin >> i;

        vector<int> type(n + m + 1);
        
        for (int i = 0; i < x; i++) type[a[i]] += 1;
        for (int i = 0; i < y; i++) type[b[i]] += 2;

        ll ans = 0;
        int cntA = 0, cntB = 0;
        int cnt_all = 0;
        for (int i = n + m; i >= 0; i--)
        {
            cerr << "type[" << i << "] = " << type[i] << '\n';
            if (type[i] == 0) continue;
            else if (type[i] == 1)
            {
                if (cntA == n) continue;
                cntA++;
            }
            else if (type[i] == 2)
            {
                if (cntB == m) continue;
                cntB++;
            }
            
            ans += i;
            cnt_all++;

            if (cnt_all >= n + m - 1) break;
        }

        cout << ans << '\n';
    };

    while (t--) solve();
}