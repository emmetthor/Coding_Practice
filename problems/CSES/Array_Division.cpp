// Date: 2026-05-21
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

    vector<ll> arr(n); for (auto &i : arr) cin >> i;

    ll low = *max_element(arr.begin(), arr.end()), hi = 1e18;
    while (low <= hi)
    {
        ll mid = (low + hi) / 2;

        auto check = [&](ll mid) -> bool
        {
            int cnt = 0;
            ll sum = 0;
            for (int i = 0; i < n; i++) {
                if (sum + arr[i] <= mid)
                {
                    sum += arr[i];
                }
                else
                {
                    cnt++;
                    sum = arr[i];
                }
            }
            if (sum >= 0) cnt++;

            cerr << mid << ' ' << cnt << '\n';

            return (cnt <= k);
        };

        if (check(mid))
            hi = mid - 1;
        else
            low = mid + 1;
    }

    cout << low;
}