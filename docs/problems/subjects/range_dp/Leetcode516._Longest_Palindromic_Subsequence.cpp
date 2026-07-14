/*
Date: 2026-07-14

Tags: range_dp
Independent: 5
Understanding: 5
Implementation: 5
Recognition: 5
*/
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
    int longestPalindromeSubseq(string s) {
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n));
        vector<vector<bool>> visi(n, vector<bool>(n));

        auto dfs = [&](auto self, int l, int r) -> int
        {
            if (l > r) return 0;
            if (l == r) return 1;
            
            if (visi[l][r]) return dp[l][r];
            visi[l][r] = 1;

            dp[l][r] = max({
                self(self, l + 1, r),
                self(self, l, r - 1),
                (s[l] == s[r] ? self(self, l + 1, r - 1) + 2 : 0)
            });

            return dp[l][r];
        };

        return dfs(dfs, 0, n - 1);
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
}