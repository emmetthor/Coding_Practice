/*
Date: 2026-07-12

Tags: graph_modeling, dijkstra
Independent: 5
Understanding: 4
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

struct Edge
{
    int to_pt;
    ll w;
    int type;
};

struct Record
{
    ll length;
    int city_cnt;
};

struct State
{
    ll length;
    int at_pt;
    int city_cnt;

    bool operator>(const State &other) const
    {
        return (length == other.length ? city_cnt > other.city_cnt : length > other.length);
    }
};

int ori_n;

struct Dijkstra {
    const ll INF = 1e18;
    /*e 的儲存是 {點, 權重}*/
    vector<vector<Edge>> e;
    vector<Record> dis;
    vector<int> visi;
    int n;

    Dijkstra(int _n) : n(_n), e(_n + 1) {}

    void add_edge(int x, Edge g) {
        e[x].push_back(g);
    }

    vector<Record> shortest_path(int st) {
        /* pool 的儲存是 {權重, 點}*/
        priority_queue<State, vector<State>, greater<State>> pool;
        
        dis.assign(n + 1, Record{INF, -1});
        visi.assign(n + 1, 0);

        dis[st] = Record{0, 1};
        pool.push(State{0, st, 1});
        
        while (pool.size()) {
            auto [v, x, c] = pool.top();
            pool.pop();

            visi[x - (x / ori_n) * ori_n] = 1;
            cerr << "visiting " << x << "[ " << x - (x / ori_n) * ori_n << " ]\n";

            for (auto [y, v2, type] : e[x]) {
                if (visi[y - (y /ori_n) * ori_n]) {
                    cerr << "visi " << y << '\n';
                    continue;
                }
                else if (dis[y].length > v + v2) {
                    dis[y].length = v + v2;
                    dis[y].city_cnt = c + 1;
                    pool.push(State{dis[y].length, y, dis[y].city_cnt});
                    cerr << x << " -> " << y <<'\n';
                }
                else if (dis[y].length == v + v2 && dis[y].city_cnt < c + 1)
                {
                    dis[y].city_cnt = c + 1;
                    pool.push(State{dis[y].length, y, dis[y].city_cnt = c + 1});
                    cerr << x << " -> " << y << '\n';
                }
            }
        }

        return dis;
    }
};


int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, m, f, k; cin >> n >> m >> f >> k;

    ori_n = n;

    Dijkstra dij(n + n * k + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v; ll w; cin >> u >> v >> w;
        for (int j = 0; j <= k; j++)
        {
            int new_u = u + j * n;
            int new_v = v + j * n;
            dij.add_edge(new_u, Edge{new_v, w, 0});
            dij.add_edge(new_v, Edge{new_u, w, 0});
        }
    }

    for (int i = 0; i < f; i++)
    {
        int u, v; ll w; cin >> u >> v >> w;
        for (int j = 1; j <= k; j++)
        {
            int new_u = u + (j - 1) * n;
            int new_v = v + j * n;
            dij.add_edge(new_u, Edge{new_v, w, 1});
        }
    }

    auto res = dij.shortest_path(1);

    ll ans = dij.INF;
    int city_cnt = 0;
    for (int i = 0; i <= k; i++)
    {
        cerr << res[n + i * n].length << ' ' << res[n + i * n].city_cnt << '\n';
        if (res[n + i * n].length <= ans)
        {
            ans = res[n + i * n].length;
            city_cnt = max(city_cnt, res[n + i * n].city_cnt);
        }
    }

    if (ans == dij.INF) cout << -1;
    else cout << ans << ' ' << city_cnt;
}
