// Date: 2026-03-22
// Tags: 組合數, 區間 DP
/*
解法：使用區間 dp[l][r] := 把 [l, r] 清空有幾種操作，
每次把 s[l] 與 s[i] (l <= i <= r) 配對，如果 s[l] == s[i] (同字)
就可以做合併，也就是把 dp[l][i] 與 dp[i + 1][r] 做合併 (中間與右邊。
但是在合併時，操作可以交替做，因此還需要利用組合數，可以轉換問題為：
    在 dp[l][i] + dp[i + 1][r] 的操作數中，要隨機擺入 dp[l][i] 的操作，請問有幾種可能？
就可以用 C n 取 k 解決
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

    const long long MOD = 1e9 + 7;
    
    string s; cin >> s;
    int n = s.size();

    vector<vector<long long>> C(n + 1, vector<long long>(n + 1, 0));
    C[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }

    vector<vector<long long>> dp(n, vector<long long>(n));
    vector<vector<bool>> visi(n, vector<bool>(n));
    // dp[l][r] := 把 [l:r] 清空有幾種方法

    auto f = [&](auto self, int l, int r) -> long long {
        if (l > r) return 1; // 空區間
        if ((r - l) % 2 == 0) return 0; // 區間長 奇數

        if (visi[l][r]) return dp[l][r];
        visi[l][r] = 1;
        
        long long ans = 0;

        for (int i = l + 1; i <= r; i += 2) {
            if (s[l] == s[i]) {
                int total_len = r - l + 1;
                int mid_len = i - l + 1;

                long long left_ways = self(self, l + 1, i - 1);
                long long right_ways = self(self, i + 1, r);
                long long combin = C[total_len / 2][mid_len / 2];

                long long total_ways = (left_ways * right_ways) % MOD;
                total_ways = (total_ways * combin) % MOD;
                ans += total_ways;
                ans %= MOD;
            }
        }

        return dp[l][r] = ans;
    };

    cout << f(f, 0, n - 1);
}