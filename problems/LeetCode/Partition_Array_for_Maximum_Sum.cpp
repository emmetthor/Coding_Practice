// Date: 2026-05-19
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
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        int dp[501] = {};
        dp[0] = 0;

        for (int i = 0; i < n; i++)
        {
            int ma = 0;
            for (int j = 1; j <= k && i + j <= n; j++)
            {
                ma = max(ma, arr[i + j - 1]);
                dp[i + j] = max(dp[i + j], dp[i] + j * ma);
            }
        }

        return dp[n];
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
}