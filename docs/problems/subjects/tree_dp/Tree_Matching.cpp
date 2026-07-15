/*
Date: 2026-07-15

Tags: subtree_merge_dp
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
    
    int n; cin >> n;

    vector<vector<int>> e(n + 1); for (int i = 0; i < n - 1; i++)
    {
        int a, b; cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    vector<array<int, 2>> dp(n + 1);
    auto dfs = [&](auto self, int x, int p) -> void
    {
        for (auto y : e[x])
        {
            if (y == p) continue;
            self(self, y, x);

            int a = dp[x][1];
            int b = dp[x][0];
            int c = dp[y][1];
            int d = dp[y][0];

            int ndp1 = max(a + c, b + d + 1);
            int ndp0 = b + c;

            dp[x][0] = ndp0;
            dp[x][1] = ndp1;
        }
    };

    dfs(dfs, 1, 1);

    cout << dp[1][1];
}