// Date: 2026-05-23
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

    vector<int> valid(m); for (auto &i : valid) cin >> i;

    sort(valid.begin(), valid.end());

    vector<pair<int, int>> interval(n); for (auto &[l, r] : interval) cin >> l >> r;

    sort(interval.begin(), interval.end(), [&](auto a, auto b) -> bool{
        if (a.second != b.second) return a.second < b.second;
        return a.first < b.first;
    });

    vector<int> ans;
    int lst = -1;
    for (int i = 0, j = 0; j < n; j++) {
        auto [l, r] = interval[j];

        if (l <= lst && lst <= r) continue;

        while (i + 1 < m && valid[i + 1] <= r) i++;
        
        if (!(l <= valid[i] && valid[i] <= r))
        {
            cout << -1;
            return 0;
        }

        lst = valid[i];
        ans.push_back(valid[i]);
    }

    int sz = ans.size();
    cout << sz << '\n';
    for (int i = 0; i < sz; i++) {
        cout << ans[i] << " \n"[i == sz - 1];
    }
}