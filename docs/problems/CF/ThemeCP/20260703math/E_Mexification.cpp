/*
Date: 2026-07-03

Tags:
Independent:
Understanding:
Implementation:
Recognition:

Mistakes:
*/
#include <bits/stdc++.h>
#include <numeric>
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

    auto solve = []() -> void
    {
        int n, k; cin >> n >> k;

        vector<int> a(n); for (auto &i : a) cin >> i;

        vector<int> cnt(n + 1);
        for (auto i : a) cnt[i]++;
        
        ll res[4] = {};

        for (int i = 0; i < 4; i++)
        {
            int mex = -1;
            int cnt_to_mex = 0;
            for (int i = 0; i <= n; i++)
            {
                if (cnt[i] == 0 && mex == -1) mex = i;
                if (cnt[i] == 1)
                {
                    if (mex == -1)
                    {
                        cnt[i] = cnt[i];
                    }
                    else
                    {
                        cnt_to_mex += cnt[i];
                        cnt[i] = 0;
                    }
                }
                if (cnt[i] > 1)
                {
                    if (mex == -1)
                    {
                        cnt_to_mex += cnt[i];
                        cnt[i] = 0;
                    }
                    else
                    {
                        cnt_to_mex += cnt[i];
                        cnt[i] = 0;
                    }
                }
            }

            if (mex != -1) cnt[mex] += cnt_to_mex;

            ll ans = 0;
            for (int i = 0; i <= n; i++)
            {
                cerr << cnt[i] << " \n"[i == n];
                ans += 1ll * i * cnt[i];
            }

            res[i] = ans;
        }

        if (k < 4)
        {
            cout << res[k - 1] << '\n';
        }
        else if (res[1] == res[3])
        {
            cout << (k % 2 == 0 ? res[1] : res[2]) << '\n';
        }
        else if (res[0] == res[2])
        {
            cout << (k % 2 == 0 ? res[1] : res[0]) << '\n';
        }
    };

    while (t--) solve();
}