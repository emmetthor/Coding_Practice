/*
Date: 2026-07-01

Tags: 1d_prefix_sum, greedy
Independent: 5
Understanding: 5
Implementation: 4
Recognition: 5

Mistakes: debugging_slow
*/
#include <bits/stdc++.h>
#include <cassert>
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
    
    int n, s, k; cin >> n >> s >> k;
    s--;

    vector<ll> prefix(n + 1);
    for (int i = 0; i < n; i++)
    {
        ll ai; cin >> ai;
        prefix[i + 1] = prefix[i] + ai;
    }

    auto get_prefix = [&](int l, int r) -> ll
    {
        if (l > r) return 0;
        if (!(0 <= l && l < n)) return 0;
        if (!(0 <= r && r < n)) return 0;
        return prefix[r + 1] - prefix[l];
    };

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == s) continue;
        int dis = abs(s - i);
        if (dis <= k)
        {
            if (i < s)
            {
                ll res = get_prefix(i, s) + get_prefix(s + 1, min(n - 1, s + k - 2 * dis));
                cerr << res << '\n';
                ans = max(ans, res);
            }
            else {
                ll res = get_prefix(s, i) + get_prefix(max(0, s - (k - 2 * dis)), s - 1);
                cerr << res << '\n';
                ans = max(ans, res);
            }
        }
    }

    cout << ans;
}