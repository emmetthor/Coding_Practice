/*
Date: 2026-07-29

Tags: dijkstra
Independent: 4
Understanding: 5
Implementation: 5
Recognition: 5
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

const int MOD = 1e9 + 7;

struct Dijkstra
{
    int n;
    vector<vector<pair<int, ll>>> e;
    vector<ll> dis;
    vector<int> cnt;
     
    Dijkstra (int _n)
    : n(_n), e(_n), dis(_n, (ll)1e18), cnt(_n) {};
    
    void add_edge(int u, int v, ll w)
    {
        e[u].push_back({v, w});
    }

    void sp(int root)
    {
        using pp = pair<ll, int>;
        priority_queue<pp, vector<pp>, greater<pp>> pool;
        
        pool.push({0, root});
        dis[root] = 0;
        cnt[root] = 1;

        while (pool.size())
        {
            auto [dd, x] = pool.top(); pool.pop();

            if (dd > dis[x]) continue;

            for (auto [y, w] : e[x])
            {
                if (dis[y] > dis[x] + w)
                {
                    dis[y] = dis[x] + w;
                    cnt[y] = cnt[x];
                    pool.push({dis[y], y});
                }
                else if (dis[y] == dis[x] + w)
                {
                    cnt[y] = (cnt[y] + cnt[x]) % MOD;
                }
            }
        }
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n, m, q, s, t; cin >> n >> m >> q >> s >> t;

    vector<int> a(q); for (auto &i : a) cin >> i;

    Dijkstra dij_s(n + 1), dij_t(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v; ll w; cin >> u >> v >> w;

        dij_s.add_edge(u, v, w);
        dij_s.add_edge(v, u, w);
        dij_t.add_edge(u, v, w);
        dij_t.add_edge(v, u, w);
    }

    dij_s.sp(s);
    dij_t.sp(t);

    auto &dis_s = dij_s.dis;
    auto &dis_t = dij_t.dis;
    auto &cnt_s = dij_s.cnt;
    auto &cnt_t = dij_t.cnt;

    for (auto aa : a)
    {

        cout << dis_s[aa] + dis_t[aa] << ' ' << (1ll * cnt_s[aa] * cnt_t[aa]) % MOD << '\n';
    }
}