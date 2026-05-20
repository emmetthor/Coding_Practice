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

    void chmax(double &x, double v) {
        if (x < v) x = v;
    }

    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        const int MAX_N = 100 + 5;

        double dp[MAX_N][MAX_N] = {};
        for (int i = 0; i < MAX_N; i++) for (int j = 0; j < MAX_N; j++) dp[i][j] = -INF;
        dp[0][0] = 0;

        int prefix[MAX_N] = {};
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        double cost[MAX_N][MAX_N] = {};
        for (int l = 1; l <= n; l++) for (int r = l; r <= n; r++) {
            cost[l][r] = double(prefix[r] - prefix[l - 1]) / (r - l + 1);
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                for (int l = i - 1; l >= 0; l--) {
                    chmax(dp[i][j], dp[l][j - 1] + cost[l + 1][i]);
                }
            }
        }

        return dp[n][k];
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
}