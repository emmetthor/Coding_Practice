/*
Date: 2026-07-01

Tags: dfs, bit_enumeration
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
    
    int n, m; cin >> n >> m;

    vector<ll> topic_cost(n + 1);
    for (int i = 1; i <= n; i++)
    {
        ll p, c; cin >> p >> c;
        topic_cost[i] = p - c;
    }

    vector<vector<int>> e(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
    }

    ll ans = 0;
    for (int i = 0; i < (1 << n); i++)
    {
        vector<int> valid(n + 1);
        for (int j = 0; j < n; j++)
        {
            valid[j + 1] = ((i >> j) & 1);
            cerr << valid[j + 1] << ' ';
        }
        cerr << '\n';
        
        vector<bool> visi(n + 1);
        bool ok = 1;

        for (int i = 1; i <= n; i++)
        {
            if (valid[i])
            {
                auto dfs = [&](auto self, int x) -> bool
                {
                    if (visi[x]) return valid[x];
                    visi[x] = 1;

                    if (!valid[x]) return false;

                    for (auto y : e[x])
                    {
                        if (!self(self, y)) return false;
                    }

                    return true;
                };

                if (!dfs(dfs, i)) ok = 0;
            }
        }

        if (ok)
        {
            ll res = 0;
            for (int i = 1; i <= n; i++)
            {
                res += (valid[i] ? 1 : 0) * topic_cost[i];
            }

            ans = max(ans, res);
        }
    }

    cout << ans;
}