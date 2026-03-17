// Date: 2026-03-17
/*
Tags: LIS, dp記憶體優化

解法：使用 LIS 的概念，令
dp[i][j] := 若結合了前 i 項 s1 與前 j 項 s2 且合併的字串前綴是 s3，可否達成

會發現 dp[i][j] 只會轉移至 dp[i + 1][j] 與 dp[i][j + 1]
因此可以優化一個維度變成 dp[2][s2.size()]
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();

        if (n + m != s3.size()) return false;

        int dp[105][105] = {};
        dp[0][0] = 1;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i < n && s3[i + j] == s1[i]) {
                    dp[i + 1][j] |= dp[i][j];
                }
                if (j < m && s3[i + j] == s2[j]) {
                    dp[i][j + 1] |= dp[i][j];
                }
            }
        }

        return dp[n][m];
    }
};

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();

        if (n + m != s3.size()) return false;

        int dp[2][105] = {};
        int id1 = 0, id2 = 1;
        dp[0][0] = 1;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                dp[id2][j] = 0;
            }

            for (int j = 0; j <= m; j++) {
                if (i < n && s3[i + j] == s1[i]) {
                    dp[id2][j] |= dp[id1][j];
                }
                if (j < m && s3[i + j] == s2[j]) {
                    dp[id1][j + 1] |= dp[id1][j];
                }
            }

            swap(id1, id2);
        }

        return dp[id2][m];
    }
};