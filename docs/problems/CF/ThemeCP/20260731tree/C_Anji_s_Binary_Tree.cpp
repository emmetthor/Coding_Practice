/*
Date: 2026-07-31

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
        int n; cin >> n;
        string s; cin >> s; s = ' ' + s;

        vector<array<int, 2>> e(n + 1);
        for (int i = 1; i <= n; i++) cin >> e[i][0] >> e[i][1];

        vector<int> dp(n + 1, 1e9);
        auto dfs = [&](auto self, int x) -> int
        {
            if (e[x][0] == 0 && e[x][1] == 0) return dp[x] = 0; // a leaf
            
            if (e[x][0] != 0) dp[x] = min(dp[x], self(self, e[x][0]) + (s[x] == 'L' ? 0 : 1));
            if (e[x][1] != 0) dp[x] = min(dp[x], self(self, e[x][1]) + (s[x] == 'R' ? 0 : 1));

            return dp[x];
        };

        cout << dfs(dfs, 1) << '\n';
    };

    while (t--) solve();
}