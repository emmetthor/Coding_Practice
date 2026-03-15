// Date: 2026-03-13
/*
Tags: 樹dp

解法：
dp[i][j] := 在點 i 選或不選 (與子節點連線)，最多可以選幾對 match
就可以分別更新 dp[i][0] 與 dp[i][1]
*/
#include <bits/stdc++.h>
#ifdef LOCAL
    bool Debug = 1;
#else
    bool Debug = 0;
#endif
#define cerr if (Debug) cerr
using namespace std;

signed main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<vector<int>> e(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }

    vector<array<int, 2>> dp(n + 1);
    /*
    dp[i][j] := 在點 i 選或不選 (與子節點連線)，最多可以選幾對 match
    dp[i][0] += max dp[child][0], dp[child][1]
    dp[i][1] = dp[i][0]

    先去掉原本的影響，再加入連線的結果
    dp[i][1] = max(dp[i][1], dp[i][0] - max(dp[child][0], dp[child][1]) + dp[child][0] + 1)
    */ 

    auto dfs = [&](auto self, int x, int lst) -> void {
        for (auto y : e[x]) {
            if (y == lst) continue;
            self(self, y, x);
            dp[x][0] += max(dp[y][0], dp[y][1]);
        }
        for (auto y : e[x]) {
            if (y == lst) continue;
            dp[x][1] = max(dp[x][1], dp[x][0] - max(dp[y][0], dp[y][1]) + dp[y][0] + 1);
        }
    };
    dfs(dfs, 1, 1);

    cout << max(dp[1][0], dp[1][1]);
}