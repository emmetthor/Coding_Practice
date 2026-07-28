/*
Date: 2026-07-27

Tags:
Independent:
Understanding:
Implementation:
Recognition:

Mistakes:
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

struct Vec
{
    ll x, y;

    Vec operator-(const Vec &b) const
    {
        return Vec{x - b.x, y - b.y};
    }

    Vec operator+(const Vec &b) const
    {
        return Vec{x + b.x, y + b.y};
    }
};

ll dot(const Vec &a, const Vec &b)
{
    return a.x * b.x + a.y * b.y;
}

ll cross(const Vec &a, const Vec &b)
{
    return a.x * b.y - b.x * a.y;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n; cin >> n;

    vector<array<ll, 2>> p(n); for (auto &[x, y] : p) cin >> x >> y;

    Vec point_root = {p[0][0], p[0][1]};
    vector<Vec> all_vecs;

    for (int i = 1; i < n; i++)
    {
        Vec point_it = {p[i][0], p[i][1]};

        all_vecs.push_back(point_it - point_root);
    }

    int sz = all_vecs.size();
    vector<int> cross_not_0(sz);
    int cross_not_0_cnt = 0;
    for (int i = 0; i < sz; i++)
    {
        for (int j = i + 1; j < sz; j++)
        {
            if (cross(all_vecs[i], all_vecs[j]) != 0)
            {
                cross_not_0[i]++;
                cross_not_0[j]++;
                cross_not_0_cnt += 2;
            }
        }
    }

    // 第一位就是 coach
    if (cross_not_0_cnt == (n - 1) * (n - 2))
    {
        cout << p[0][0] << ' ' << p[0][1] << '\n';
        return 0;
    }

    for (int i = 0; i < sz; i++)
    {
        cerr << cross_not_0[i] << '\n';
        if (cross_not_0[i] > 1)
        {
            cout << p[i + 1][0] << ' ' << p[i + 1][1] << '\n';
            return 0;
        }
    }

    cout << -1 << ' ' << -1 << '\n';
}