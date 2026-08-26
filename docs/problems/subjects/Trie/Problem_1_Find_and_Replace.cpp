/*
Date: 2026-08-26

Tags:
Independent:
Understanding:
Implementation:
Recognition:

Mistakes:
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
    
    ll l, r, k; cin >> l >> r >> k;

    vector<pair<char, string>> oper(k);
    for (auto &[c, s] : oper) cin >> c >> s;

    int node_cnt = 26;
    vector<int> curr(26);
    for (int i = 0; i < 26; i++) curr[i] = i + 1;

    vector<ll> node_size(1e6, 1);
    vector<vector<int>> e(1e6);
    for (int i = k - 1; i >= 0; i--)
    {
        auto [c, s] = oper[i];

        if (s.size() == 1)
        {
            curr[c - 'a'] = curr[s[0] - 'a'];
            continue;
        }

        int new_node = ++node_cnt;

        ll new_node_size = 0;
        for (auto cc : s)
        {
            e[new_node].push_back(curr[cc - 'a']);
            new_node_size = min((ll)1e18, new_node_size + node_size[curr[cc - 'a']]);
        }
        curr[c - 'a'] = new_node;
        node_size[new_node] = new_node_size;
    }

    auto dfs = [&](auto self, int x, ll l, ll r) -> void
    {
        l = max(l, 1ll);
        r = min(r, node_size[x]);

        if (l > r) return;

        cerr << ">>> at " << x << " | trying " << l << "~" << r << '\n';
        if (1 <= x && x <= 26)
        {
            cout << char('a' + x - 1);
            return;
        }

        ll curr_pos = 0;
        for (auto y : e[x])
        {
            if (curr_pos >= r) break;

            self(self, y, l - curr_pos, r - curr_pos);
            curr_pos = min((ll)1e18, curr_pos + node_size[y]);
        }
    };

    dfs(dfs, curr[0], l, r);
}