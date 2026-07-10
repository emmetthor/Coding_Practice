/*
Date: 2026-06-13

Tags: sort, lower_upper_bound
Independent: 5
Understanding: 5
Implementation: 5
Recognition: 4
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
    
    int n; cin >> n;

    vector<array<int, 2>> pt(n);
    for (auto &[x, y] : pt) cin >> x >> y;

    sort(pt.begin(), pt.end());

    set<int> lst_y;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        auto [x, y] = pt[i];

        auto it = lst_y.lower_bound(y);

        if (it == lst_y.begin()) ans++;

        cerr << ans << '\n';
        lst_y.insert(y);
    }

    cout << ans;
}