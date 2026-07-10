/*
Date: 2026-07-02

Tags: greedy, lower_upper_bound, sequence_containers
Independent: 5
Understanding: 5
Implementation: 5
Recognition: 5
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
    
    const int INF_INF = 1e9 + 2e5 + 15;
    const int MAX_NMK = 2e5 + 15;

    int t; cin >> t;

    ll robot_pos[MAX_NMK] = {};
    ll spike_pos[MAX_NMK] = {};
    bool dead[MAX_NMK] = {};
    auto solve = [&]() -> void
    {
        int n, m, k; cin >> n >> m >> k;

        for (int i = 0; i < n; i++) dead[i] = 0;

        for (int i = 0; i < n; i++) cin >> robot_pos[i];
        for (int i = 0; i < m; i++) cin >> spike_pos[i];
        spike_pos[m] = -INF_INF;
        spike_pos[m + 1] = INF_INF;
        sort(spike_pos, spike_pos + m + 2);

        vector<vector<int>> robot_death_steps(2 * k + 5);
        vector<bool> visi(2 * k + 5, 0);
        for (int i = 0; i < n; i++)
        {
            auto it = upper_bound(spike_pos, spike_pos + m + 2, robot_pos[i]);
            ll l = *prev(it) - robot_pos[i], r = *it - robot_pos[i];
            if (-k <= l && l <= k) robot_death_steps[l + k].push_back(i);
            if (-k <= r && r <= k) robot_death_steps[r + k].push_back(i);
        }

        int curr = 0;
        int ans = n;
        string steps; cin >> steps;
        for (int i = 0; i < k; i++)
        {
            if (steps[i] == 'L') curr--;
            if (steps[i] == 'R') curr++;

            if (!visi[curr + k])
            {
                for (auto r : robot_death_steps[curr + k])
                {
                    if (dead[r]) continue;
                    dead[r] = 1;
                    ans--;
                }
            }
            visi[curr + k] = 1;

            cout << ans << " \n"[i == k - 1];
        }
    };

    while (t--) solve();
}