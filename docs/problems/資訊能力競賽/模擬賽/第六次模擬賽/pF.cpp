/*
Date: 2026-11-07

Tags: associative_containers, implementation
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
    
    int n, q; cin >> n >> q;

    set<pair<int, int>> interval;
    interval.insert({-1, n + 2});

    auto calc = [](int l, int r) -> int
    {
        int len = r - l + 1 - 4;
        return max(0, (len + 1) / 2);
    };

    int ans = calc(-1, n + 2);
    while (q--)
    {
        char c; int p; cin >> c >> p;

        if (c == '+')
        {
            auto in = prev(interval.upper_bound(make_pair(p, p)));
            auto [l, r] = *in;
            ans -= calc(l, r);
            interval.erase(in);

            ans += calc(l, p);
            interval.insert({l, p});

            ans += calc(p, r);
            interval.insert({p, r});
        }
        else if (c == '-')
        {
            auto left = prev(interval.upper_bound(make_pair(p, p)));
            auto right = next(left);
            auto [l1, r1] = *left;
            auto [l2, r2] = *right;
            
            ans -= calc(l1, r1);
            interval.erase(left);
            
            ans -= calc(l2, r2);
            interval.erase(right);

            ans += calc(l1, r2);
            interval.insert({l1, r2});
        }

        for (auto [l, r] : interval) cerr << '[' << l << ", " << r << "] ";
        cerr << '\n';

        cout << ans << '\n';
    }
}