/*
Date: 2026-10-11
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
    
    int n; ll w; cin >> n >> w;

    vector<pair<ll, ll>> dish(n); for (auto &[a, b] : dish) cin >> a >> b;

    sort(dish.begin(), dish.end());

    ll ma = 0;
    for (int i = 0; i < (1 << n); i++)
    {
        ll total_w = 0, total_d = 0;
        for (int j = 0; j < n; j++)
        {
            if ((i >> j) & 1)
            {
                total_w += dish[j].second;
                total_d += dish[j].first;
            }
        }

        if (total_w <= w) ma = max(ma, total_d);
    }

    cout << ma;
}