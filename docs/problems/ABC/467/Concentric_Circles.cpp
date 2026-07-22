/*
Date: 2026-07-18

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
using i128 = __int128_t;
#define cerr if(debug_mode) cerr

struct Vec
{
    i128 x;
    i128 y;

    Vec operator-(const Vec &b) const
    {
        return {x - b.x, y - b.y};
    }

    Vec operator+(const Vec &b) const
    {
        return {x + b.x, y + b.y};
    }
};

i128 cross(Vec &a, Vec &b)
{
    return a.x * b.y - a.y * b.x;
}

i128 dot(Vec &a, Vec &b)
{
    return a.x * b.x + a.y * b.y;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int t; cin >> t;

    auto solve = [&]() -> void
    {
        ll px, py, qx, qy, rx, ry, sx, sy; cin >> px >> py >> qx >> qy >> rx >> ry >> sx >> sy;

        Vec P = {px, py};
        Vec Q = {qx, qy};
        Vec R = {rx, ry};
        Vec S = {sx, sy};
        Vec vec_pq = Q - P;
        Vec vec_rs = S - R;

        // 平行
        if (cross(vec_pq, vec_rs) == 0)
        {
            Vec vec_mid = (S + R) - (P + Q);
            if (dot(vec_mid, vec_pq) == 0)
            {
                cout << "Yes\n";
            } else cout << "No\n";
        }
        else cout << "Yes\n";
    };
    
    while (t--) solve();
}
    
