/*
Date: 2026-07-24

Tags: geometry
Independent: 4
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
    vector<pair<int, int>> pp(n); for (auto &[a, b] : pp) cin >> a >> b;
    sort(pp.begin(), pp.end());

    cout << n + 2 << '\n';
    for (auto [a, b] : pp) cout << a << ' ' << b << '\n';
    cout << 1000000000 << ' ' << 1000000000 << '\n';
    cout << -1000000000 << ' ' << 1000000000;
}