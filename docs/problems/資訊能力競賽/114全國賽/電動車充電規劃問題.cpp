/*
Date: 2026-08-10

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

const ll INF = 1e18;

struct BF
{
    int n;
    vector<tuple<int, int, ll>> edge;
    vector<ll> dis;
    ll limit;
    BF(int _n, vector<tuple<int, int, ll>> _edge, ll _B) : n(_n), edge(_edge), dis(_n, INF), limit(_B)
    {
    }

    vector<ll> shortest_path()
    {
        for (int t = 0; t < n - 1; t++)
        {
            for (auto [u, v, w] : edge)
            {
                if (dis[v] > dis[u] + w)
                {
                    if (dis[u] + w > 0) continue;
                    dis[v] = max(-limit, dis[u] + w);
                }
            }
        }

        return dis;
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n, m, s, t; cin >> n >> m >> s >> t;
    ll B, b; cin >> B >> b;

    vector<tuple<int, int, ll>> e(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v; ll w; cin >> u >> v >> w;
        e.push_back({u, v, - w});
    }

    int g; cin >> g;
    vector<int> chargers(g); for (auto &i : chargers) cin >> i;

    BF bf(n + 1, e, B);

    bf.dis[s] = -b;
    auto res = bf.shortest_path();
    
    ll low = 0, hi = B;
    while (low <= hi)
    {
        ll mid = (low + hi) / 2;
        cerr << "charging " << mid << '\n';

        BF bf2(n + 1, e, B);
        for (auto charger : chargers)
        {
            if (res[charger] > 0) continue; // can't reach the charger
            ll chargeto = min(B, -res[charger] + mid);
            
            bf2.dis[charger] = -chargeto;
            cerr << "charger " << charger << " becomes " << chargeto << '\n';
        }

        auto res2 = bf2.shortest_path();

        if (res2[t] <= 0) hi = mid - 1;
        else low = mid + 1;
    }

    ll ans1 = (res[t] <= 0 ? 0 : -1);
    ll ans2 = (low > B ? -1 : low);
    
    if (ans1 != -1) cout << ans1;
    else if (ans2 != -1) cout << ans2;
    else cout << -1;
}