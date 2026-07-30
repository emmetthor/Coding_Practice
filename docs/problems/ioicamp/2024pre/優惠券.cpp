/*
Date: 2026-07-28

Tags: associative_containers
Independent: 5
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
    
    int n, m; cin >> n >> m;
    vector<array<int, 4>> cop(n); for (auto &[l, r, c, w] : cop) cin >> l >> r >> c >> w;
    vector<int> b(m + 1); for (int i = 1; i <= m; i++) cin >> b[i];

    vector<vector<array<int, 2>>> trans_l(m + 1), trans_r(m + 1); for (int i = 0; i < n; i++)
    {
        auto [l, r, c, w] = cop[i];
        cerr << l << ' ' << r << ' ' << c << ' ' << w << '\n';
        trans_l[l].push_back({r,i});
        trans_r[r].push_back({l, i});
    }

    struct data
    {
        ll c, w;
        int id;

        bool operator<(const data &b) const
        {
            return (w == b.w ? id < b.id : w > b.w);
        }
    };

    set<data> dd;
    vector<data> curr_cop(n);

    for (int i = 1; i <= m; i++)
    {
        // cerr << "=== processing " << i << ", current b = " << b[i] << " ===\n";
        for (auto [r, id] : trans_l[i])
        {
            auto [l, _r, c, w] = cop[id];
            dd.insert(data{c, w, id});
            curr_cop[id] = data{c, w, id};

            // cerr << "add " << id << " with " << c << " tickets, weight " << w << '\n';
        }

        // cerr << "in stack: ";
        // for (auto [c, w, id] : dd) cerr << id << ' '; cerr << '\n';

        ll ans = 0;
        while (b[i] > 0 && dd.size())
        {
            auto [c, w, id] = *dd.begin();
            // cerr << "> using " << id << " with " << c << " tickets, weight " << w << " <\n";

            if (b[i] - c < 0)
            {
                int use = b[i]; b[i] = 0;

                // cerr << "use " << use << " amount of " << id << '\n';

                c -= use;
                ans += 1ll * use * w;
                dd.erase(curr_cop[id]);
                curr_cop[id] = {c, w, id};
                dd.insert(curr_cop[id]);
            }
            else
            {
                // cerr << "use all " << id << '\n';
                b[i] -= c;
                ans += 1ll * c * w;
                dd.erase(curr_cop[id]);
            }
        }

        cout << ans << " \n"[i == m];

        for (auto [l, id] : trans_r[i])
        {
            if (dd.find(curr_cop[id]) != dd.end()) dd.erase(curr_cop[id]);
        }
    }
    
    int changedtext  = 0;
}