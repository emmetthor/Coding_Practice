/*
Date: 2026-07-08

Tags: graph_modeling, graph, dfs
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

    auto solve = [&]() -> void
    {
        int n; cin >> n;

        vector<ll> a(n + 1); for (int i = 1; i <= n; i++) cin >> a[i];

        vector<ll> need_length(n + 1);

        for (ll i = 2; i <= n; i++) need_length[i] = i + a[i] - 1;

        map<ll, vector<ll>> e;
        for (int i = 2; i <= n; i++)
        {
            e[need_length[i]].push_back(need_length[i] + i - 1);
        }

        map<ll, bool> visi;
        auto dfs = [&](auto self, ll x) -> void
        {
            if (visi[x]) return;
            visi[x] = 1;

            for (auto y : e[x])
            {
                self(self, y);
            }
        }; dfs(dfs, n);

        cout << prev(visi.end()) -> first << '\n';
    };

    while (t--) solve();
}