/*
Date: 2026-07-15

Tags: range_dp, binary_search
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

using ll = unsigned long long;
#define cerr if(debug_mode) cerr

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n; ll m; cin >> n >> m;

    vector<string> smith(n); for (auto &s : smith) cin >> s;
    vector<string> order(n); for (auto &s : order) cin >> s;

    // 預處理 p
    // p[i][j] := 第 i 項 order 要 smith j 去做可以做幾項
    vector<vector<ll>> p(n, vector<ll>(n));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
    {
        int cnt_order[26] = {};
        for (auto c : order[i])
        {
            cnt_order[c - 'a']++;
        }

        for (auto c : smith[j])
        {
            if (cnt_order[c - 'a'])
            {
                p[i][j]++;
            }
        }

        cerr << p[i][j] << " \n"[j == n - 1];
    }

    ll efficiency[] = {3, 1, 2, 0};

    ll low = 0, hi = 1e5 + 10;
    while (low <= hi)
    {
        ll k = (low + hi) / 2;

        vector<vector<ll>> dp(n, vector<ll>(n, 0));

        for (int len = 0; len <= n; len++)
        {
            for (int l = 0; l + len < n; l++)
            {
                int r = l + len;
                
                dp[l][r] = max(
                    (l + 1 < n ? dp[l + 1][r] : 0),
                    (r - 1 >= 0 ? dp[l][r - 1] : 0)
                ) + cost(l, r);
            }
        }

        ll res = dp[0][n - 1];
        cerr << k << ' ' << res << '\n';
        if (res >= m) hi = k - 1;
        else low = k + 1;
    }

    cout << low;
}