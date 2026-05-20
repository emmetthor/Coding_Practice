// Date: 2026-05-20
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    bool debug_mode = 1;
#else
    bool debug_mode = 0;
#endif

using ll = long long;
#define cerr if(debug_mode) cerr

class Solution {
public:
    const int INF = 1e9;

    void chmin(int &x, int v) {
        if (x > v) x = v;
    }

    int palindromePartition(string s, int k) {
        int n = s.size();

        int dp[101][101] = {};
        for (int i = 0; i < 101; i++) for (int j = 0; j < 101; j++) dp[i][j] = INF;
        // front i items has created k palidromes. dp[i][j] is the minimum cost.

        dp[0][0] = 0;

        int cost[101][101] = {};

        for (int center = 0; center < n; center++) {
            for (int l = 0; center - l >= 0 && center + l < n; l++) {
                int left = center - l, right = center + l;
                if (left + 1 < n && right - 1 >= 0) cost[left][right] = cost[left + 1][right - 1] + (s[left] != s[right] ? 1 : 0);

                if (right + 1 < n) {
                    if (left + 1 < n && right + 1 - 1 >= 0) cost[left][right + 1] = cost[left + 1][right + 1- 1] + (s[left] != s[right + 1] ? 1 : 0);
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                for (int l = 1; i - l >= 0; l++) {
                    chmin(dp[i][j], dp[i - l][j - 1] + cost[i - l + 1 - 1][i - 1]);
                }
            }
        }

        return dp[n][k];
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
}