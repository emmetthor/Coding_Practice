/*
Date: 2026-07-23

Tags: knapsack_problems
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
    
    int n, s; cin >> n >> s;

    vector<array<int, 2>> new_items;
    for (int i = 0; i < n; i++)
    {
        int w, v, c; cin >> w >> v >> c;

        int cnt = 1;
        int total = 0;
        while (total + cnt <= c)
        {
            cerr << "add " << w * cnt << ' ' << v * cnt << '\n';
            new_items.push_back({w * cnt, v * cnt});
            total += cnt;
            cnt *= 2;
        }

        if (c - total > 0)
        {
            cerr << "add " << w * (c - total) << ' ' << v * (c - total) << '\n';
            new_items.push_back({w * (c - total), v * (c - total)});
        }
    }

    int new_n = new_items.size();
    vector<vector<int>> dp(new_n + 1, vector<int>(s + 1, -1e9));
    dp[0][0] = 0;

    auto chmax = [&](int &x, int v) -> void
    {
        if (x < v) x = v;
    };
    
    for (int i = 0; i < new_n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            dp[i + 1][j] = dp[i][j];
            if (j - new_items[i][0] >= 0)
                chmax(dp[i + 1][j], dp[i][j - new_items[i][0]] + new_items[i][1]);
        }
    }

    cout << (dp[new_n][s] < 0 ? -1 : dp[new_n][s]);
}