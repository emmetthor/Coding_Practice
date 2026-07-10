// Date: 2026-04-01
// Tags: Floyd Warshall, 分段 dp
//
// 解法：
// 可以先把字元的轉移算出來，使用 Floyd Warshall
// 題目就會變成：
// 把 S 轉成一段一段的字串且字串長度至少為 k，轉換一個字有 cost，問 minimum cost?
// 於是可以聯想到分段 dp
// dp[i][j] := 使前 i 項合法，且最後選 j 時的 minimum cost
// 每次轉移分為開新段落 (i + k) 與延伸段落 (i + 1 (i != 0))
// 就可以解題
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    bool debug_mode = 1;
#else
    bool debug_mode = 0;
#endif

using ll = long long;
#define cerr if(debug_mode) cerr

/*
calc shortest weight to change char x -> char y

dp[i][j] := 使前 i 項合法，且最後選 j 時的 minimum cost
    dp[i + k][k] = min_forall { dp[i][j] + sum cost}
    dp[i + 1][j] = min_forall { dp[i][j] + cost}

ans = min_forall { dp[n][i] }
* sum cost -> use prefix
*/

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    const int INF = 1e9;
    const int MAX_N = 1e5 + 5;
    const int MAX_M = 30;

    // === file ==

    ifstream fin("cowmbat.in");
    ofstream fout("cowmbat.out");

    #define cin fin
    #define cout fout
    
    // === input ===
    int n, m, k; cin >> n >> m >> k;

    string s; cin >> s;

    int minimum_change_weight[MAX_M][MAX_M] = {};
    for (int i = 0; i < m; i++) for (int j = 0; j < m; j++) {
        cin >> minimum_change_weight[i][j];
    }

    // === calc weight ===
    for (int k = 0; k < m; k++) for (int i = 0; i < m; i++) for (int j = 0; j < m; j++) {
        minimum_change_weight[i][j] = min(
            minimum_change_weight[i][j],
            minimum_change_weight[i][k] + minimum_change_weight[k][j]
        );
    }

    // === calc prefix ===
    int prefix[MAX_N][MAX_M] = {};

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            prefix[i][j] += prefix[i - 1][j] + minimum_change_weight[s[i - 1] - 'a'][j];
        }
    }

    // === dp ===
    int dp[MAX_N][MAX_M] = {};
    for (int i = 0; i <= n; i++) for (int j = 0; j < m; j++) dp[i][j] = INF;

    for (int i = 0; i < m; i++) {
        dp[0][i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int l = 0; l < m; l++) {
                if (i + k > n) continue;

                dp[i + k][l] = min(dp[i + k][l], dp[i][j] + prefix[i + k][l] - prefix[i][l]);
            }

            if (i == 0) continue;

            // char change from s_i to j
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + minimum_change_weight[s[i] - 'a'][j]);
        }
    }

    int ans = INF;
    for (int i = 0; i < m; i++) {
        ans = min(ans, dp[n][i]);
    }

    cout << ans;
}