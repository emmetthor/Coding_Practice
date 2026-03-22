// Date: 2026-03-22
// Tags: 排容原理, 數學
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
    
    int t; cin >> t;

    auto solve = []() -> void {
        ll a, b, c, m; cin >> a >> b >> c >> m;

        ll abc = lcm(lcm(a, b), lcm(a, c));
        ll ab = lcm(a, b);
        ll ac = lcm(a, c);
        ll bc = lcm(b, c);

        ll abc_cnt = m / abc;
        ll ab_cnt = m / ab;
        ll ac_cnt = m / ac;
        ll bc_cnt = m / bc;
        ll a_cnt = m / a;
        ll b_cnt = m / b;
        ll c_cnt = m / c;

        array<ll, 4> a_get = {}, b_get = {}, c_get = {};
        
        // for person a
        a_get[3] += abc_cnt;
        a_get[2] += ab_cnt + ac_cnt - abc_cnt - abc_cnt;
        a_get[1] += a_cnt - ab_cnt - ac_cnt + abc_cnt;

        cout << a_get[1] * 6 + a_get[2] * 3 + a_get[3] * 2 << ' ';

        // for person b
        b_get[3] += abc_cnt;
        b_get[2] += ab_cnt + bc_cnt - abc_cnt - abc_cnt;
        b_get[1] += b_cnt - ab_cnt - bc_cnt + abc_cnt;

        cout << b_get[1] * 6 + b_get[2] * 3 + b_get[3] * 2 << ' ';

        // for person c
        c_get[3] += abc_cnt;
        c_get[2] += ac_cnt + bc_cnt - abc_cnt - abc_cnt;
        c_get[1] += c_cnt - ac_cnt - bc_cnt + abc_cnt;

        cout << c_get[1] * 6 + c_get[2] * 3 + c_get[3] * 2 << '\n';
    };

    while (t--) solve();
}