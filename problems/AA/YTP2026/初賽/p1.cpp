/*
Date: 2026-07-07
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
    
    int n, q; cin >> n >> q;

    vector<pair<ll, ll>> scores(n); for (auto &[a, b] : scores) cin >> a >> b;

    while (q--)
    {
        ll x, y; cin >> x >> y;

        bool score = false;
        for (auto [r, s] : scores)
        {
            if (x * x + y * y <= r * r)
            {
                cout << s << '\n';
                score = 1;
                break;
            }
        }

        if (!score) cout << 0 << '\n';
    }
}