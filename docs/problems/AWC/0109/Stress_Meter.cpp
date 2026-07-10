/*
Date: 2026-07-09
*/
#include <bits/stdc++.h>
#include <cstdint>
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
    
    int n, k, q; cin >> n >> k >> q;

    vector<ll> change(n + 1);
    for (int i = 1; i <= n; i++)
    {
        ll a, b; cin >> a >> b;
        change[i] = a - b;
    }

    struct Item
    {
        int from;
        int counter;
        int8_t stress;
    }; vector<vector<Item>> records(n + 1);

    auto dfs = [&](auto self, int pos, ll stress, int counter, int from) -> void
    {
        if (pos > n) return;

        cerr << "from " << from << " | at " << pos << " | counter " << counter << " | stress " << stress << '\n';

        int nxt_pos = pos + 1;
        ll changed_stress = max(0ll, stress + change[pos]);
        int nxt_counter = counter + (changed_stress >= k ? 1 : 0);
        if (nxt_counter - counter == 1) changed_stress = 0;

        records[pos].push_back({from, nxt_counter, (int8_t)changed_stress});

        self(self, nxt_pos, changed_stress, nxt_counter, from);
    };

    for (int i = 1; i <= n; i++)
    {
        dfs(dfs, i, 0, 0, i);
    }

    while (q--)
    {
        int a, b; cin >> a >> b;

        //cout << "=== " << a << ' ' << b << " ===\n";

        for (auto [f, c, s] : records[b])
        {
            if (f == a)
            {
                cout << c << ' ' << s << '\n';
            }
        }
    }
}