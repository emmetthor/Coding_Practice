/*
Date: 2026-07-01
*/
#include <algorithm>
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
    int n, m; cin >> n >> m;

    vector<ll> r(n); for (auto &i : r) cin >> i;
    sort(r.begin(), r.end());
    vector<ll> s(m); for (auto &i : s) cin >> i;

    ll mi = *min_element(s.begin(), s.end());

    cout << upper_bound(r.begin(), r.end(), mi) - r.begin();
}