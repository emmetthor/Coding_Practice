/*
Date: 2026-07-15

Tags:
Independent:
Understanding:
Implementation:
Recognition:

Mistakes:
*/
#include <bits/stdc++.h>
#include <queue>
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
    
    int n, m; cin >> n >> m;
    vector<ll> w(n + 1); for (int i = 1; i <= n; i++) cin >> w[i];
    vector<vector<int>> e(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b; cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    // [0] 不選 / [1] 選，且可以全選子節點 / [2] 選，但不可全選子節點
    vector<array<ll, 3>> dp(n + 1);
    for (int i = 1; i <= n; i++) dp[i][1] = dp[i][2] = w[i];

    auto dfs = [&](auto self, int x, int p) -> void
    {
        // {value, node, 是否有選}
        priority_queue<ll> p1, p2;
        ll base = w[x];

        for (auto y : e[x])
        {
            if (y == p) continue;

            self(self, y, x);
            base += dp[y][0];
            p1.push(dp[y][2] - dp[y][0]);
            p2.push(dp[y][2] - dp[y][0]);
            dp[x][0] += max(dp[y][0], dp[y][1]);
        }

        dp[x][1] = base;
        dp[x][2] = base;

        for (int i = 0; p1.size() && i < m; i++)
        {
            ll v = p1.top(); p1.pop();
            if (v < 0) break;
            dp[x][1] += v;
        }

        for (int i = 0; p2.size() && i < m - 1; i++)
        {
            ll v = p2.top(); p2.pop();
            if (v < 0) break;
            dp[x][2] += v;
        }

        cerr << x << ' ' << dp[x][0] << ' ' << dp[x][1] << ' ' << dp[x][2] << '\n';
    };

    dfs(dfs, 1, 1);

    cout << max({dp[1][0], dp[1][1]});
}