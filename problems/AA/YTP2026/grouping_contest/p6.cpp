// Date: 2026-05-23
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
    
    int n; cin >> n;
    vector<array<int, 2>> limit(n);
    for (auto &arr : limit)
    {
        cin >> arr[0] >> arr[1];
    }

    auto f = [&](ll mid) -> bool
    {
        ll curr_l = 0, curr_r = 0;
        for (int i = 0; i < n; i++) {
            curr_l -= mid, curr_r += mid;
            ll l = limit[i][0], r = limit[i][1];

            ll match_l = max(l, curr_l), match_r = min(r, curr_r);

            cerr << l << ' ' << r << ' ' << match_l << ' ' << match_r << '\n';

            if (match_l > match_r)
                return false;
            curr_l = match_l;
            curr_r = match_r;
        }

        return true;
    };

    ll low = 0, hi = 2e9;
    while (low <= hi)
    {
        ll mid = (low + hi) / 2;
        cerr << mid << '\n';

        if (f(mid))
            hi = mid - 1;
        else
            low = mid + 1;
    }

    cout << low;

    // cout << f(low);
}