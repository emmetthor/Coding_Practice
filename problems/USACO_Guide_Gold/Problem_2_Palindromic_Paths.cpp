// Date: 2026-03-21
// Tag: 二維地圖 dp, 雙人 dp
/*
解法：由於回文必須同時推進頭尾，於是使用 dp[step][r1][r2] := 走 step 第一人在 r1 第二人在 r2 這時的答案是啥
由於有記憶體限制，於是必須壓縮 step 變成用 id1, id2 維護
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

    ifstream fin("palpath.in");
    ofstream fout("palpath.out");

    #define cin fin
    #define cout fout
    
    const long long MOD = 1e9 + 7;

    auto upd = [&](long long &x, long long v) -> void {
        v %= MOD;
        x += v;
        x %= MOD;
    };

    int n; cin >> n;

    if (n == 1) {
        cout << 1;
        return 0;
    }

    vector<string> mp(n);
    for (auto &s : mp) cin >> s;

    vector<vector<vector<long long>>> dp(2, vector<vector<long long>>(n, vector<long long>(n)));
    int id1 = 0, id2 = 1;
    if (mp[0][0] == mp[n - 1][n - 1]) dp[id1][0][n - 1] = 1;

    for (int step = 1; step <= n - 1; step++) {
        // init
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[id2][i][j] = 0;
            }
        }

        // calc next
        for (int r1 = 0; r1 <= step; r1++) {   
            for (int r2 = n - 1; r2 >= n - 1 - step; r2--) {
                int c1 = step - r1;
                int c2 = 2 * n - 2 - step - r2;
 
                if (mp[r1][c1] == mp[r2][c2]) {
                    if (r1 != 0 && r2 != n - 1) upd(dp[id2][r1][r2], dp[id1][r1 - 1][r2 + 1]);
                    if (r1 != 0 && c2 != n - 1) upd(dp[id2][r1][r2], dp[id1][r1 - 1][r2]);
                    if (c1 != 0 && r2 != n - 1) upd(dp[id2][r1][r2], dp[id1][r1][r2 + 1]);
                    if (c1 != 0 && c2 != n - 1) upd(dp[id2][r1][r2], dp[id1][r1][r2]);
                }
            }
        }

        swap(id1, id2);
    }
    swap(id1, id2);

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        upd(ans, dp[id2][i][i]);
    }

    cout << ans;
}