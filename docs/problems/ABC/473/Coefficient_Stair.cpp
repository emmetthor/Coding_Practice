/*
Date: 2026-08-29

Tags: dfs, brute_force
Independent: 4
Understanding: 5
Implementation: 5
Recognition: 5

Mistakes: wrong_complexity
*/
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
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
    
    int n, k; cin >> n >> k;

    int tmp[11] = {};

    auto dfs = [&](auto self, int cnt, int sum) -> void
    {
        if (cnt == n - 1)
        {
            if (sum % n == 0)
            {
                for (int i = 0; i < n - 1; i++) cout << tmp[i] << ' ';
                cout << sum / n << '\n';
            }
            return;
        }


        for (int i = 0; i * (cnt + 1) <= sum; i++)
        {
            tmp[cnt] = i;
            self(self, cnt + 1, sum - i * (cnt + 1));
        }
    };

    dfs(dfs, 0, k);
}