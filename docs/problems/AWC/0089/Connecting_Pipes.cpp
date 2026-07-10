/*
Date: 2026-06-11

Tags: greedy
Independent: 5
Understanding: 3
Implementation: 3 
Recognition: 5

Mistakes:special_case_not_found
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
    
    ll n, d, k, c; cin >> n >> d >> k >> c;
    vector<array<ll, 2>> pipe(n); for (auto &[a, b] : pipe) cin >> a >> b;

    ll ans = 0;
    ll ma_pipe = -1e18;
    int connect_points = 0;
    for (auto [a, b] : pipe)
    {
        if (b == 1)
            a -= c;

        if (a > k)
        {
            ans += a;
            connect_points++;
        }

        ma_pipe = max(ma_pipe, a);

        cerr << ans << ' ' << ma_pipe << '\n';
    }

    ll result = (connect_points ? ans - k * (connect_points - 1) : 0);
    result = max(result, ma_pipe);
    cout << (result >= d ? result : -1);
}