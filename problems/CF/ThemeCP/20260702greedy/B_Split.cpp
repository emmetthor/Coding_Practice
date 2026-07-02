/*
Date: 2026-07-02

Tags: greedy, equation_optimize
Independent: 5
Understanding: 5
Implementation: 5
Recognition: 5
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

    auto solve = []() -> void
    {
        int n; cin >> n;
        vector<int> a(2 * n); for (auto &i : a) cin >> i;

        vector<int> cnt(2 * n + 1);
        for (int i = 0; i < 2 * n; i++) cnt[a[i]]++;

        int ans = 0;
        int cnt_of_even = 0;
        int cnt_of_4k = 0;
        int cnt_of_odd = 0;
        int cnt_of_single = 0;
        for (int i = 1; i <= 2 * n; i++)
        {
            if (cnt[i] == 0) continue;
            else if (cnt[i] % 2 == 0 && cnt[i] / 2 % 2 == 1) cnt_of_even++;
            else if (cnt[i] % 4 == 0) cnt_of_4k++;
            else cnt_of_odd++;
        }

        cerr << cnt_of_odd << ' ' << cnt_of_even << ' ' << cnt_of_4k << '\n';

        ans += 4 * (cnt_of_4k / 2);
        if (cnt_of_odd >= 2 && cnt_of_4k % 2 == 1)
        {
            ans += 4;
            cnt_of_odd -= 2;
        }
        ans += 2 * cnt_of_even;
        ans += cnt_of_odd;

        cout << ans << '\n';
    };

    while (t--) solve();
}