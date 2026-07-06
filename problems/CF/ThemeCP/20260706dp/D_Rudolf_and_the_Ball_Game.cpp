/*
Date: 2026-07-06

Tags: dfs, graph_modeling
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

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int t; cin >> t;

    auto solve = []() -> void
    {
        int n, m, x; cin >> n >> m >> x;

        vector<array<int, 2>> record(m);
        for (int i = 0; i < m; i++)
        {
            int r; char dir; cin >> r >> dir;
            record[i] = {r, (dir == '?' ? 2 : dir - '0')};
        }

        vector<vector<bool>> visi(m + 1, vector<bool>(n));
        set<int> res;
        auto dfs = [&](auto self, int round, int p) -> void
        {
            if (visi[round][p]) return;
            visi[round][p] = 1;

            if (round == m)
            {
                res.insert(p);
                return;
            }

            auto [r, dir] = record[round];

            if (dir == 0)
            {
                self(self, round + 1, (p + r) % n);
            }
            else if (dir == 1)
            {
                self(self, round + 1, (p - r + n) % n);
            }
            else
            {
                self(self, round + 1, (p + r) % n);
                self(self, round + 1, (p - r + n) % n);
            }
        };

        dfs(dfs, 0, x - 1);

        int sz = res.size();
        cout << sz << '\n';

        auto it = res.begin();
        for (int i = 0; i < sz; i++)
        {
            cout << *it + 1 << " \n"[i == sz - 1];
            it = next(it);
        }
    };

    while (t--) solve();
}