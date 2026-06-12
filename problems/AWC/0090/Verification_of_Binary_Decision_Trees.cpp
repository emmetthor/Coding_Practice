/*
Date: 2026-06-12

Tags: complicated_implementation, dfs, tree
Independent: 5
Understanding: 4
Implementation: 3
Recognition: 5

Mistakes: reading_misunderstanding
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
    
    int n, m; cin >> n >> m;

    vector<array<ll, 2>> rg(n + 1), time(n + 1);
    for (int i = 1; i <= n; i++)
    {
        ll l, r, p, q; cin >> l >> r >> p >> q;
        rg[i] = {l, r};
        time[i] = {p, q};
    }

    vector<vector<pair<int, int>>> e(n + 1);
    vector<int> enter_cnt(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, b; cin >> u >> v >> b;
        e[u].push_back({v, b});

        if (v == 1)
        {
            // entering root -> false
            cout << "NO";
            return 0;
        }

        enter_cnt[v]++;
    }

    for (int i = 2; i <= n; i++)
    {
        if (enter_cnt[i] != 1)
        {
            cout << "NO";
            return 0;
        }
    }

    vector<bool> visi(n + 1);

    auto dfs = [&](auto self, int x) -> int
    {
        if (visi[x]) return true;
        visi[x] = 1;

        auto [l_x, r_x] = rg[x];
        auto [p_x, q_x] = time[x];

        int cnt0 = 0, cnt1 = 0;
        ll cnt0_r = 0, cnt1_l = 0;
        for (auto [y, b] : e[x])
        {
            auto [l_y, r_y] = rg[y];
            auto [p_y, q_y] = time[y];

            if (b == 0) 
            {
                cnt0++;
                cnt0_r = r_y;
            }
            else
            {
                cnt1++;
                cnt1_l = l_y;
            }

            if (l_x < l_y && r_y < r_x && p_y == q_x)
            {
                if (!self(self, y))
                    return false;
            }
            else
            {
                return false;
            }
        }

        if (cnt0 == 1 && cnt1 == 1)
        {
            if (!(cnt0_r < cnt1_l)) return false;
        }

        if (cnt0 <= 1 && cnt1 <= 1)
            return true;
        else
            return false;
    };

    vector<bool> visi2(n + 1);
    auto dfs2 = [&](auto self, int x) -> void
    {
        if (visi2[x]) return;
        visi2[x] = 1;
        for (auto [y, b] : e[x])
            self(self, y);
    };

    dfs2(dfs2, 1);

    for (int i = 1; i <= n; i++)
    {
        if (visi2[i] == 0)
        {
            cout << "NO";
            return 0;
        }
    }

    cout << (dfs(dfs, 1) ? "YES" : "NO");
}