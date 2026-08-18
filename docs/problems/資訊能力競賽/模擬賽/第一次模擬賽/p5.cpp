/*
Date: 2026-07-12

Tags: greedy
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
    
    int n; cin >> n;

    vector<ll> p(1 << n); for (auto &i : p) cin >> i;

    sort(p.begin(), p.end());

    vector<vector<ll>> res(n + 1);
    res[0] = p;

    ll ans = 0;
    for (int stage = 0; stage < n; stage++)
    {
        for (int i = 0; i < res[stage].size(); i += 2)
        {
            ans += res[stage][i + 1] - res[stage][i];
            res[stage + 1].push_back(res[stage][i + 1]);
        }
    }

    cout << ans;
}