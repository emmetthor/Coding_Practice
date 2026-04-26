// Date: 2026-04-25
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

    map<int, ll> sum;
    for (int i = 0; i < n; i++) {
        int ai; cin >> ai;
        sum[ai] += ai;
    }

    vector<pair<ll, int>> sums;
    for (auto [key, value] : sum) sums.emplace_back(value, key);

    sort(sums.begin(), sums.end());

    ll ans = 0;
    for (int i = 0; i < max(0, (int)sums.size() - k); i++) ans += sums[i].first;

    cout << ans;
}