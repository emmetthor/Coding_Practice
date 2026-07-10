// Date: 2026-03-22
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

    auto solve = []() -> void {
        int n; cin >> n;
        vector<int> a(n);
        set<pair<int, int>> pp;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            pp.insert({a[i], i});
        }

        int cnt = 0;
        int lst = n;
        while (pp.size()) {
            cnt++;

            auto [v, idx] = *pp.rbegin();

            for (int i = idx; i < lst; i++) {
                pp.erase({a[i], i});
            }

            lst = idx;
        }

        cout << cnt << '\n';
    };

    while (t--) solve();
}