#include <bits/stdc++.h>
using namespace std;

signed main() {
    /*第一式：DFS求樹直徑端點*/
    int n;
    vector<vector<int>> e(n + 1);
    vector<vector<int>> dis(n + 1, vector<int>(n + 1));
    /*dis[i][j] := i 到 j 的最短距離*/

    auto dfs = [&](auto self, int root, int x, int lst) -> void {
        for (auto y : e[x]) {
            if (y == lst) continue;

            self(self, root, y, x);
            dis[root][x] = max(dis[root][y], dis[root][x] + 1);
        }
    };

    /*紀錄 root子樹的最遠路，最遠的一定是直徑的端點*/

    int root = 1;
    dfs(dfs, root, root, root);

    int u = 0;
    for (int i = 1; i <= n; i++) {
        if (dis[root][i] > dis[root][u])
            u = i;
    }

    /*從計算出的直徑端點再次紀錄 u 子樹的最遠路，最遠的一定是直徑的另一端點*/

    root = 2;
    dfs(dfs, root, u, root);

    int v = 0;
    for (int i = 1; i <= n; i++) {
        if (dis[root][i] > dis[root][v])
            v = i;
    }

    /*u-v 即是樹直徑*/

    /*第二式：dp求樹直徑距離*/

    vector<vector<int>> dp(n + 1, vector<int>(2));
    /*dp[i] := 點 i 最遠的路徑與次遠的路徑，兩條路徑相加就是答案*/

    auto upd = [](vector<int> _dp, int v) -> void {
        if (v > _dp[0]) {
            _dp[1] = _dp[0];
            _dp[0] = v;
        }
        else if (v > _dp[1])
            _dp[1] = v;
    };

    int ans = 0;
    auto dfs2 = [&](auto self, int x, int lst) -> void {
        for (auto y : e[x]) {
            if (y == lst) continue;

            self(self, y, x);

           upd(dp[x], dp[y][0] + 1);
        }

        ans = max(ans, dp[x][0] + dp[x][1]);
    };

    cout << ans;
}
