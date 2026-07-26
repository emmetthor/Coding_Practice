/*
Date: 2026-07-25

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
    
    int t; cin >> t;

    auto solve = []()
    {
        int n, k; cin >> n >> k;

        vector<ll> a(n);

        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> cnt(n + 1);

        ll res[4] = {};
        for (int t = 0; t < 4; t++)
        {
            for (int i = 0; i <= n; i++) cnt[i] = 0;

            for (int i = 0; i < n; i++)
            {
                cnt[a[i]]++;
            }

            ll curr_mex = -1;
            for (int i = 0; i <= n; i++)
            {
                if (curr_mex == -1 && cnt[i] == 0) curr_mex = i;
            }

            ll ans = 0;
            for (int i = 0; i < n; i++)
            {
                if (cnt[a[i]] >= 2) a[i] = curr_mex;
                else if (cnt[a[i]] == 1) a[i] = min(curr_mex, a[i]);

                ans += a[i];
            }

            res[t] = ans;
        }

        if (k <= 4) cout << res[k - 1] << '\n';
        else if (res[1] == res[3]) cout << (k % 2 == 0 ? res[1] : res[2]) << '\n';

    };

    while (t--) solve();
}