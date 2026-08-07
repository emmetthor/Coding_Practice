/*
Date: 2026-08-06

Tags: associative_containers
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
        int n, m; cin >> n >> m;

        vector<ll> sta(n); for (auto &i : sta) cin >> i;

        vector<vector<ll>> mp(n, vector<ll>(m)); for (auto &v : mp) for (auto &i : v) cin >> i;

        multiset<ll> stk;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) stk.insert(mp[i][j]);

        int ans = m;

        for (int i = 0; i < n; i++)
        {
            ll res = 0;
            auto it = stk.end();
            for (int j = 0; j < m; j++)
            {
                it--;
                cerr << "at " << i << ' ' << j << '\n';
                res += *it;

                if (res >= sta[i]) ans = min(ans, j + 1);
            }

            cerr << "layer " << i << ' ' << ans << '\n';

            for (int j = 0; j < m; j++)
            {
                cerr << "erasing " << mp[i][j] << '\n';
                stk.erase(stk.find(mp[i][j]));
            }
        }

        cout << ans << '\n';
    };

    while (t--) solve();
}