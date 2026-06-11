/*
Date: 2026-06-11

Tags: same_side_two_pointer, 1d_prefix_sum
Independent:5
Understanding:4
Implementation:5
Recognition:4

Mistakes:wrong_idea, overcomplicated_solution
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
    
    ll n, b; cin >> n >> b;

    vector<ll> beauty(n); for (auto &i : beauty) cin >> i;
    vector<ll> prefix(n + 1); for (int i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + beauty[i - 1];
    vector<ll> cost(n - 1); for (int i = 0; i < n - 1; i++) cin >> cost[i];
    
    ll curr_cost = 0;
    ll curr_beauty = 0;
    ll ans = 0;
    for (int l = 0, r = 0; r < n - 1; r++)
    {
        curr_cost += cost[r];

        while (l <= r && curr_cost > b)
        {
            curr_cost -= cost[l];
            l++;
        }

        cerr << l << ' ' << r << ' ' << curr_cost << '\n';

        ans = max(ans, prefix[r + 2] - prefix[l]);
    }

    cout << ans;
}