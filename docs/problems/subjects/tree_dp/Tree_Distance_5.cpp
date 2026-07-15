/*
Date: 2026-07-15

Tags: tree_dp
Independent: 3
Understanding: 5
Implementation: 5
Recognition: 5

Mistakes:
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
    
    int n; cin >> n;

    vector<vector<int>> e(n + 1); for (int i = 0; i < n - 1; i++)
    {
        int a, b; cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    ll ans = 0;
    vector<ll> sz(n + 1, 1);
    auto dfs = [&](auto self, int x, int p) -> ll
    {
        ll res = 0;
        for (auto y : e[x])
        {
            if (y == p) continue;
            res += self(self, y, x);
            sz[x] += sz[y];
        }

        for (auto y : e[x])
        {
            if (y == p) continue;

            res += sz[y] * (n - sz[y]);
        }

        return res;
    };

    cout << dfs(dfs, 1, 1);
}