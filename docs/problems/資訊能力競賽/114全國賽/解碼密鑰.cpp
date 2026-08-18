/*
Date: 2026-08-11

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

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n, k; cin >> n >> k;

    vector<ll> key(k); for (auto &i : key) cin >> i;

    ll low = 0, hi = 1e18;
    while (low <= hi)
    {
        ll mid = (low + hi) / 2;
        ll res = 0;
        for (int i = 1; i < (1 << k); i++)
        {
            vector<ll> nums;
            for (int j = 0; j < k; j++)
            {
                if ((i >> j) & 1) nums.push_back(key[j]);
            }
            int sz = nums.size();
            ll all_lcm = nums[0];
            for (int j = 1; j < sz; j++) all_lcm = lcm(all_lcm, nums[j]);

            res += (sz % 2 == 0 ? -1 : 1) * (mid / all_lcm);
        }

        cerr << mid << ' ' << res << '\n';

        if (res >= n) hi = mid - 1;
        else low = mid + 1;
    }
    
    cout << low;
}