/*
Date: 2026-07-30

Tags: range_dp
Independent: 4
Understanding: 5
Implementation: 5
Recognition: 5
*/
#include <bits/stdc++.h>
#include <cstring>
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
   
    const int SZ = 90;

    int n, m; cin >> n >> m;

    string a, b; cin >> a >> b;

    auto chmax = [](int &x, int v) -> void
    {
        if (v > x) x = v;
    };

    int dp[SZ][SZ][SZ][SZ] = {};
    memset(dp, -1, sizeof(dp));

    auto dfs = [&](auto self, int l1, int r1, int l2, int r2) -> void
    {
        auto &res = dp[l1][r1][l2][r2];
        if (res != -1) return;
        if (l1 > r1)
        {
            res = 0;
            return;
        } 
        if (l2 > r2)
        {
            res = 0;
            return;
        }
        if (l1 == r1)
        {
            for (int i = l2; i <= r2; i++) if (a[l1] == b[i])
            {
                res = 1; return;
            }
            res = 0;
            return;
        }
        if (l2 == r2)
        {
            for (int i = l1; i <= r1; i++) if (a[i] == b[l2])
            {
                res = 1; return;
            }
            res = 0;
            return;
        }

        if (l1 + 1 < n) self(self, l1 + 1, r1, l2, r2);
        if (r1 - 1 >= 0) self(self, l1, r1 - 1, l2, r2);
        if (l2 + 1 < m) self(self, l1, r1, l2 + 1, r2);
        if (r2 - 1 >= 0) self(self, l1, r1, l2, r2 - 1);

        if (l1 + 1 < n) chmax(res, dp[l1 + 1][r1][l2][r2]);
        if (r1 - 1 >= 0) chmax(res, dp[l1][r1 - 1][l2][r2]);
        if (l2 + 1 < m) chmax(res, dp[l1][r1][l2 + 1][r2]);
        if (r2 - 1 >= 0) chmax(res, dp[l1][r1][l2][r2 - 1]);

        if (a[l1] == a[r1] && a[r1] == b[l2] && b[l2] == b[r2])
        {
            if (l1 + 1 < n && r1 - 1 >= 0 && l2 + 1 < m && r2 - 1 >= 0)
            {
                self(self, l1 + 1, r1 - 1, l2 + 1, r2 - 1); 
                chmax(res, dp[l1 + 1][r1 - 1][l2 + 1][r2 - 1] + 2);
            }
        }
    };

    dfs(dfs, 0, n - 1, 0, m - 1);

    cout << dp[0][n - 1][0][m - 1];
}