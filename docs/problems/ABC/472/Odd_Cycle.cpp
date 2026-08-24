/*
Date: 2026-08-22

Tags: find_cycle
Independent: 4
Understanding: 5
Implementation: 5
Recognition: 5
*/
#include <bits/stdc++.h>
#include <cassert>
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

    auto solve = []()
    {
        int n, m; cin >> n >> m;

        vector<vector<int>> e(n + 1);
        for (int i = 0; i < m; i++)
        {
            int a, b; cin >> a >> b;
            e[a].push_back(b);
            e[b].push_back(a);
        }

        const pair<int, int> NOT = {-1, -1};
        vector<int> mark(n + 1); // 0: not visi / 1: white / 2: black
        vector<int> parent(n + 1);

        bool answered = 0;
        auto dfs = [&](auto self, int x, int p) -> void
        {
            if (mark[x] != 0)
            { 
                if (mark[x] + mark[p] != 3 && !answered)
                {
                    cerr << x << ' ' << p << '\n';
                    vector<int> ans;
                    ans.push_back(p);

                    int tmp = parent[p];
                    while (tmp != x)
                    {
                        cerr << tmp << '\n';
                        ans.push_back(tmp);
                        tmp = parent[tmp];
                    }

                    cout << ans.size() + 1 << '\n';
                    for (auto i : ans) cout << i << ' ';
                    cout << x << '\n';
                    
                    answered = 1;
                }
                return;
            }
            mark[x] = (mark[p] == 1 ? 2 : 1);
            parent[x] = p;

            for (auto y : e[x])
            {
                self(self, y, x);
            }
        };

        mark[0] = 2;
        dfs(dfs, 1, 0);

        if (!answered)
        {
            cout << -1 << '\n';
        }
    };

    while (t--) solve();
}