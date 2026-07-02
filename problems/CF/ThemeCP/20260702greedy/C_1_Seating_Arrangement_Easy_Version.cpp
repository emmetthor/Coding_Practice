/*
Date: 2026-07-02

Tags: dp
Independent: 5
Understanding: 3
Implementation: 3
Recognition: 3

Mistakes: wrong_idea
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

    const int INT_INF = 1e9;
    
    int t; cin >> t;

    auto chmax = [](int &x, int v) -> void
    {
        if (v > x) x = v;
    };

    auto solve = [&]() -> void
    {
        int n, x, s; cin >> n >> x >> s;
        string p; cin >> p;

        vector<vector<int>> dp(n + 1, vector<int>(x + 1, -INT_INF));
        dp[0][0] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = x; j >= 0; j--)
            {
                int token = 0;
                if (p[i - 1] == 'I') token = 0b01;
                if (p[i - 1] == 'E') token = 0b10;
                if (p[i - 1] == 'A') token = 0b11;

                chmax(dp[i][j], dp[i - 1][j]);

                if ((token >> 0) & 1)
                {
                    cerr << p[i - 1] << " add new table after " << j << '\n';
                    if (j + 1 <= x && i - 1 >= 0)
                    {
                        chmax(dp[i][j + 1], dp[i - 1][j] + 1);
                    }
                }

                if ((token >> 1) & 1)
                {
                    cerr << p[i - 1] << " old table\n";
                    if (i - 1 >= 0 && j != 0 && j * s > dp[i - 1][j])
                    {
                        chmax(dp[i][j], dp[i - 1][j] + 1);
                    }
                }
            }
            for (int j = 0; j <= x; j++) cerr << dp[i][j] << " \n"[j == x];
        }

        int ans = 0;
        for (int i = 0; i <= x; i++)
            chmax(ans, dp[n][i]);

        cout << ans << '\n';
    };

    while (t--) solve();
}