/*
Date: 2026-07-04

Tags:
Independent:
Understanding:
Implementation:
Recognition:

Mistakes:
*/
#include <bits/stdc++.h>
#include <string>
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

    const int MAX_N_DIGIT = 1 + 5;
    
    string n; cin >> n;

    ll dp[MAX_N_DIGIT][2][3][2][10][10][10] = {};
    // 處理第幾位 / 是否在界線內 / 總和對 3 取餘 / 開始形成數字？ / 數字1 / 數字2 / 數字3

    for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) for (int k = 0; k < 10; k++)
    {
        dp[1][1][1][0][i][j][k] = 1;
    }

    string tmp = "";
    auto dfs = [&](auto self, int i, bool tight, int mod, bool started, int num1, int num2, int num3) -> ll
    {
        if (i == n.size())
        {
            cerr << tmp << '\n';
            if (mod == 0 && started) return 1;
            else return 0;
        }

        ll res = 0;
        array<int, 4> can_use_digits = {0, num1, num2, num3};
        for (int j = 0; j < 4; j++)
        {
            int d = can_use_digits[j];

            if (num1 == 0) continue;

            bool new_tight = tight && (n[i] - '0' == d);
            if (!started && d == 0)
            {
                tmp += '0';
                res += self(self, i + 1, new_tight, mod, false, num1, num2, num3);
                tmp.pop_back();
            }
            else if (started && j != 0)
            {
                tmp += char('0' + d);
                int new_mod = (mod + d) % 3;
                res += self(self, i + 1, new_tight, new_mod, true, num1, num2, num3);
                tmp.pop_back();
            }
        }

        return res;
    };

    ll ans = 0;
    for (int i = 0; i < 10; i++) for (int j = i + 1; j < 10; j++) for (int k = j + 1; k < 10; k++)
    {
        cerr << "=== " << i << ' ' << j << ' ' << k << " ===\n";
        ans += dfs(dfs, 0, 1, 0, 0, i, j, k);
    }

    cout << ans;
}