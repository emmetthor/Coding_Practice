/*
Date: 2026-06-12

Tags: weighted_interval_scheduling_dp, dp
Independent: 3
Understanding: 5
Implementation: 5
Recognition: 1

Mistakes: not_learned, overcomplicated_solution
*/
#include <algorithm>
#include <bits/stdc++.h>
#include <stdlib.h>
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

    struct Event
    {
        int l, r;
        ll c;
    };

    vector<Event> event(n + 1); //l, r, weight
    ll sum_c = 0;
    for (int i = 1; i <= n; i++)
    {
        int l, r; ll c; cin >> l >> r >> c;
        event[i] = {l, r, c};
        sum_c += c;
    }
    
    sort(event.begin(), event.end(), [](const Event &e1, const Event &e2)
    {
        return e1.r < e2.r;
    });

    vector<ll> ends(n + 1);
    for (int i = 1; i <= n; i++)
    {
        ends[i] = event[i].r;
    }

    vector<array<ll, 2>> dp(n + 1);
    for (int i = 1; i <= n; i++)
    {
        auto [l, r, w] = event[i];
        int lst_valid_index = upper_bound(ends.begin(), ends.end(), event[i].l) - ends.begin() - 1;

        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = max(dp[lst_valid_index][0] + b + event[i].c, dp[lst_valid_index][1] + b + event[i].c);
    }

    cout << max(dp[n][0], dp[n][1]) - sum_c;
}