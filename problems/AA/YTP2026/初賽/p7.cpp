/*
Date: 2026-07-07
*/
#include <bits/stdc++.h>
#include <unordered_map>
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
    
    ll n, d; cin >> n >> d;

    vector<pair<ll, ll>> pos(n); for (auto &[a, b] : pos) cin >> a >> b;

    map<pair<ll, ll>, ll> cnt;

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        auto [x, y] = pos[i];
        for (ll nx = -d; nx <= d; nx++)
        {
            ll newy1 = y - (d - abs(nx));
            ll newy2 = y + (d - abs(nx));

            //cerr << x << ' ' << y << ' ' << x + nx << ' ' << newy1 << ' ' << newy2 << '\n';

            ans += cnt[{x + nx, newy1}];
            if (newy1 != newy2) ans += cnt[{x + nx, newy2}];
        }

        cnt[{x, y}]++;
    }

    cout << ans;
}