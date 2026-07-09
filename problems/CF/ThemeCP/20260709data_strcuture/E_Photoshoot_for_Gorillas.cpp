/*
Date: 2026-07-09

Tags: greedy
Independent: 5
Understanding: 5
Implementation: 5
Recognition: 5
*/
#include <bits/stdc++.h>
#include <functional>
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
        int n, m, k, w; cin >> n >> m >> k >> w;
        vector<ll> height(w); for (auto &i : height) cin >> i;

        sort(height.begin(), height.end(), greater<>());

        vector<int> weights;

        vector<int> tplete(n);
        for (int i = 0, j = n - 1; i <= j; i++, j--)
        {
            tplete[i] = tplete[j] = min(min(n - k + 1, k), i + 1);
        }
        for (int i = 0, j = m - 1; i <= j; i++, j--)
        {
            for (auto it : tplete)
            {
                weights.push_back(min(min(m - k + 1, k), i + 1) * it);
            }

            if (i == j) break;

            for (auto it : tplete)
            {
                weights.push_back(min(min(m - k + 1, k), i + 1) * it);
            }
        }

        sort(weights.begin(), weights.end(), greater<>());

        ll ans = 0;
        for (int i = 0; i < w; i++)
        {
            cerr << weights[i] << ' ';
            ans += height[i] * weights[i];
        }
        cerr << '\n';

        cout << ans << '\n';
    };

    while (t--) solve();
}