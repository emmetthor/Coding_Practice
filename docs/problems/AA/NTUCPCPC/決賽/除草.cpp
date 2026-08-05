/*
Date: 2026-08-05

Tags: dp, multi_source, greedy
Independent: 3
Understanding: 5
Implementation: 5
Recognition: 4
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

    int sz = n * m;
    auto id = [&](int x, int y) -> int
    {
        return (x - 1) * m + y;
    };

    vector<ll> a(sz + 1);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[id(i, j)];

    auto shortest_path_to_right = [&](int rx, int ry, vector<ll> &res) -> void
    {
        res.assign(sz + 1, (ll)1e18);
        res[id(rx, ry)] = a[id(rx, ry)];
        
        for (int j = 1; j <= m; j++)
        {
            for (int i = 2; i <= n; i++)
            {
                res[id(i, j )] = min(res[id(i, j)], res[id(i - 1, j)] + a[id(i, j)]);
            }
            for (int i = n - 1; i >= 1; i--)
            {
                res[id(i, j)] = min(res[id(i, j)], res[id(i + 1, j)] + a[id(i, j)]);
            }

            if (j + 1 > m) continue;

            for (int i = 1; i <= n; i++)
            {
                res[id(i, j + 1)] = min(res[id(i, j + 1)], res[id(i, j)] + a[id(i, j + 1)]);
            }
        }
    };

    int ux = 1, uy = 1;
    int vx = n, vy = 1;
    vector<ll> dis_u, dis_v;
    shortest_path_to_right(ux, uy, dis_u);
    shortest_path_to_right(vx, vy, dis_v);

    auto shortest_path_to_left = [&](int rx, int ry, vector<ll> &res) -> void
    {
        
        for (int j = m; j >= 1; j--)
        {
            for (int i = 2; i <= n; i++)
            {
                res[id(i, j)] = min(res[id(i, j)], res[id(i - 1, j)] + a[id(i, j)]);
            }
            for (int i = n - 1; i >= 1; i--)
            {
                res[id(i, j)] = min(res[id(i, j)], res[id(i + 1, j)] + a[id(i, j)]);
            }

            if (j - 1 < 1) continue;

            for (int i = 1; i <= n; i++)
            {
                res[id(i, j - 1)] = min(res[id(i, j - 1)], res[id(i, j)] + a[id(i, j - 1)]);
            }
        }
    };

    int sx = 1, sy = m;
    int tx = n, ty = m;
    vector<ll> dis_t, dis_s;
    dis_t.assign(sz + 1, 1e18);
    dis_s.assign(sz + 1, 1e18);
    dis_t[id(tx, ty)] = a[id(tx, ty)];
    dis_s[id(sx, sy)] = a[id(sx, sy)];

    shortest_path_to_left(sx, sy, dis_s);
    shortest_path_to_left(tx, ty, dis_t);

    vector<ll> match_st_point(sz + 1);

    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
    {
        match_st_point[id(i, j)] = dis_t[id(i, j)] + dis_s[id(i, j)] - a[id(i, j)];
    }

    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cerr << match_st_point[id(i, j)] << " \n"[j == m];

    shortest_path_to_left(sx, sy, match_st_point);

    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cerr << match_st_point[id(i, j)] << " \n"[j == m];

    ll ans = 1e18;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
    {
        int idx = id(i, j);
        ans = min(ans, dis_u[idx] + dis_v[idx] - 2 * a[idx] + match_st_point[idx]);
    }

    cout << min(dis_u[id(sx, sy)] + dis_v[id(tx, ty)], ans);
}