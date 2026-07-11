/*
Date: 2026-07-11

Tags: digit_dp
Independent: 3
Understanding: 5
Implementation: 5
Recognition: 5
*/
#include <bits/stdc++.h>
#include <string>
#include <tuple>
using namespace std;

#ifdef LOCAL
    bool debug_mode = 1;
#else
    bool debug_mode = 0;
#endif

using ll = long long;
#define cerr if(debug_mode) cerr

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    const int MOD = 998244353;

    const int MAX_N_DIGIT = 500 + 5;
    
    string n; cin >> n;

    bool visi[MAX_N_DIGIT][2][2][(1 << 10)][3] = {};
    int dp[MAX_N_DIGIT][2][2][(1 << 10)][3] = {};
    // dp[pos][started][tight][used_number][mod]
    dp[0][0][0][0][0] = 1;

    auto check = [&](bool started, int used_number, int mod) -> int
    {
        if (started)
        {
            int used_number_cnt = __builtin_popcount(used_number);
            bool has_3 = (used_number >> 3) & 1;
            bool is_3k = (mod == 0 ? 1 : 0);

            for (int i = 0; i < 10; i++)
            {
                cerr << ((used_number >> i) & 1) << ' ';
            }
            cerr << '\n';
            
            if (used_number_cnt == 3 && !has_3 && !is_3k) return 1;
            if (has_3 && used_number_cnt != 3 && !is_3k) return 1;
            if (is_3k && used_number_cnt != 3 && !has_3) return 1;
        }

        return 0;
    };

    auto dfs = [&](auto self, int pos, bool started, bool tight, int used_number, int mod) -> int
    {
        if (pos == n.size())
        {
            return check(started, used_number, mod);
        }

        if (visi[pos][started][tight][used_number][mod]) return dp[pos][started][tight][used_number][mod];
        visi[pos][started][tight][used_number][mod] = true;

        int &res = dp[pos][started][tight][used_number][mod];

        for (int use = 0; use <= (tight ? n[pos] - '0' : 9); use++)
        {
            int new_pos = pos + 1;

            bool new_started = (use == 0 ? started : true);
            
            bool new_tight = (use == n[pos] - '0' ? tight : false);

            int new_used_number = used_number;
            if (new_started == true) new_used_number = (used_number | (1 << use));

            int new_mod = mod;
            if (new_started == true) new_mod = (mod + use) % 3;

            res += self(self, new_pos, new_started, new_tight, new_used_number, new_mod);
            res %= MOD;
        }

        return res;
    };
    
    cout << dfs(dfs, 0, 0, 1, 0, 0);
}