// Date: 2026-03-20
// Tags: 交換 dp, 交換
/*
解法：將題目轉換成：
> 使用 cnt[k] 個 k，cnt[e] 個 E，cnt[y] 個 Y，若湊出的字串 T 需要以 S 交換 tt 次得出，
> 請計算 T 共有幾種可能使 tt <= K?

dp[i][j][k][c] := 使用 K i 個，使用 E j 個，使用 Y k 個，花費 c 時有幾種答案，
會發現不失一般性的以加入 K 舉例， dp[i + 1][j][k][c + cost(K)] += dp[i][j][k][c]
而 cost(K) 就是要交換這個 K 到目前位置所需的交換次數。

請注意，交換時應扣除已經被交換完成的 char

失誤：
未將 cost 計算寫下，忘記需扣除已經被交換完成的 char
*/
#include <bits/stdc++.h>
#ifdef LOCAL
    bool Debug = 1;
#else
    bool Debug = 0;
#endif
#define cerr if (0) cerr
using namespace std;

signed main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    string s; cin >> s;
    int n = s.size();
    int kk; cin >> kk;
    int max_swap = n * (n + 1) / 2;

    static long long dp[35][35][35][500] = {};
    dp[0][0][0][0] = 1;
    /*
    dp[i][j][k][c] := 使用 K i 個，使用 E j 個，使用 Y k 個，花費 c 時有幾種答案
    dp[i + 1][j][k][c + cost(K)] += dp[i][j][k][c];
    ...

    cost 就是目前剩下最前面留下的 K and so on
    */

    array<int, 3> cnt = {};
    array<vector<int>, 3> pos;

    for (int i = 0; i < n; i++) {
        int id = (s[i] == 'K' ? 0 : s[i] == 'E' ? 1 : s[i] == 'Y' ? 2 : -1);
        pos[id].emplace_back(i);
        cnt[id]++;
    }

    cerr << cnt[0] << ' ' << cnt[1] << ' ' << cnt[2] << '\n';

    auto cost = [&](int type, int idx, int i, int j, int k) -> int {
        if (idx >= cnt[type]) return 1000;

        int p = pos[type][idx];
        int removed = 0;

        for (int x = 0; x < i; x++) removed += (pos[0][x] < p);
        for (int x = 0; x < j; x++) removed += (pos[1][x] < p);
        for (int x = 0; x < k; x++) removed += (pos[2][x] < p);

        return p - removed;
    };

    for (int i = 0; i <= cnt[0]; i++) {
        for (int j = 0; j <= cnt[1]; j++) {
            for (int k = 0; k <= cnt[2]; k++) {
                for (int c = 0; c <= n * (n + 1) / 2; c++) {
                    int total_length = i + j + k;
                    array<int, 3> costs = {
                        cost(0, i, i, j, k),
                        cost(1, j, i, j, k),
                        cost(2, k, i, j, k)
                    };

                    cerr << "# " << i << ' ' << j << ' ' << k << ' ' << c << '\n';
                    cerr << costs[0] << ' ' << costs[1] << ' ' << costs[2] << '\n';

                    if (i < cnt[0] && c + costs[0] < 500) dp[i + 1][j][k][c + costs[0]] += dp[i][j][k][c];
                    if (j < cnt[1] && c + costs[1] < 500) dp[i][j + 1][k][c + costs[1]] += dp[i][j][k][c];
                    if (k < cnt[2] && c + costs[2] < 500) dp[i][j][k + 1][c + costs[2]] += dp[i][j][k][c];
                }
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i <= min(kk, max_swap); i++) {
        cerr << dp[cnt[0]][cnt[1]][cnt[2]][i] << '\n';
        ans += dp[cnt[0]][cnt[1]][cnt[2]][i];
    }

    cout << ans;
}