/*
Date: 2026-07-14

Tags: range_dp
Independent: 4
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
    const int INF = 1e9;
    static const int MAX_N = 50 + 1;
    int dp[MAX_N][MAX_N] = {};
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();

        int ans = INF;

        for (int diff = 0; diff < n; diff++)
        {
            auto id = [&](int x) -> int
            {
                if (x + diff >= n) return x + diff - n;
                else return x + diff;
            };

            // auto dfs = [&](auto self, int l, int r) -> ll
            // {
            //     if (l + 2 > r) return 0;
            //     if (l + 2 == r) return values[id(l)] * values[id(l + 1)] * values[id(l + 2)];

            //     ll &ret = dp[id(l)][id(r)];
            //     if (ret != -1) return ret;
            //     ret = LL_MAX;

            //     for (int k = l; k <= r; k++)
            //     {
            //         ret = min(
            //             ret,
            //             self(self, l, k) + self(self, k, r) + values[id(l)] * values[id(k)] * values[id(r)]
            //         );
            //     }

            //     return ret;
            // };

            // ans = min(ans, dfs(dfs, diff, n - 1 + diff));

            for (int len = 0; len < 2; len++)
            {
                for (int l = 0; l + len < n; l++)
                {
                    int r = l + len;
                    dp[l][r] = 0;
                }
            }

            for (int len = 2; len <= n; len++)
            {
                for (int l = 0; l + len < n; l++)
                {
                    int r = l + len;

                    int _l = id(l), _r = id(r);
                    dp[_l][_r] = INF;

                    for(int k = l; k <= r; k++)
                    {
                        int _k = id(k);
                        dp[_l][_r] = min(
                            dp[_l][_r],
                            dp[_l][_k] + dp[_k][_r] + values[_l] * values[_k] * values[_r]
                        );
                    }
                }
            }

            ans = min(ans, dp[id(0)][id(n - 1)]);
        }

        return ans;
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
}