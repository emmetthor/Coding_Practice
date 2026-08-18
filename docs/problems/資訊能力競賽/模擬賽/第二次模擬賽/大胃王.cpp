/*
Date: 2026-08-16

Tags:
Independent:
Understanding:
Implementation:
Recognition:

Mistakes:
*/
#include <bits/stdc++.h>
#include <queue>
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
    vector<ll> single(n); for (auto &i : single) cin >> i;

    const int MAX_ID = (1 << n) + 5;
    vector<ll> sets(MAX_ID, 1e18);
    // <cost, id>
    for (int i = 0; i < m; i++)
    {
        int cnt = 0;
        bool valid = 1;
        int k; ll s; cin >> k >> s;
        int id = 0;
        for (int j = 0; j < k; j++)
        {
            int ai; cin >> ai;

            if (((id >> (ai - 1)) & 1) == 1) valid = 0;

            id |= (1 << (ai - 1));
        }
        if (valid) sets[id] = min(sets[id], s);
    }

    vector<pair<ll, int>> remain_sets;
    for (int i = 0; i < MAX_ID; i++)
    {
        if (sets[i] != 1e18) remain_sets.push_back({sets[i], i});
    }
    int sz = remain_sets.size();
    for (auto [s, id] : remain_sets) cerr << s << ' ' << id << '\n';
    cerr << '\n';

    // using pll = pair<ll, ll>;
    // vector<ll> dis(MAX_ID, 1e18);
    // priority_queue<pll, vector<pll>, greater<pll>> pool;
    // dis[0] = 0;
    // pool.push({dis[0], 0});

    // while (pool.size())
    // {
    //     auto [v, id] = pool.top(); pool.pop();

    //     for (int i = 0; i < sz; i++)
    //     {
    //         auto [v2, id2] = remain_sets[i];
    //         if ((id & id2) > 0) continue; // overlap

    //         ll new_id = id | id2;
    //         if (dis[new_id] > v + v2)
    //         {
    //             dis[new_id] = v + v2;
    //             pool.push({dis[new_id], new_id});
    //         }
    //     }
    // }

    // ll ans = 1e18;
    // for (int i = 0; i < MAX_ID; i++)
    // {
    //     ll res = dis[i];
    //     for (int j = 0; j < n; j++)
    //     {
    //         cerr << ((i >> j) & 1);
    //         if (((i >> j) & 1) == 0) res += single[j];
    //     }
    //     cerr << ' ' << dis[i] << '\n';
    //     ans = min(ans, res);
    // }
    // cout << ans;

    vector<ll> dp(MAX_ID, 1e18);
    dp[0] = 0;

    const int FULL = (1 << n) - 1;
    for (int mask = 0; mask <= FULL; mask++)
    {
        int remain = FULL ^ mask;
        for (int sub = remain; sub >= 1; sub = (sub - 1) & remain)
        {
            // sub 是所有不和 mask 重疊的子 sub_mask

            if (sets[sub] == 1e18) continue;
            dp[mask | sub] = min(dp[mask | sub], dp[mask] + sets[sub]);

            cerr << mask << ' ' << sub << '\n';
        }
    }

    ll ans = 1e18;
    for (int i = 0; i < (1 << n); i++) 
    {
        ll res = dp[i];
        for (int j = 0; j < n; j++)
        {
            if (((i >> j) & 1) == 0) res += single[j];
        }
        ans = min(ans, res);
    }

    cout << ans;
}