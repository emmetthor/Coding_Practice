/*
Date: 2026-11-07

Tags: binary_search, greedy
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
    
    int n, k; cin >> n >> k;

    array<vector<ll>, 2> p;

    for (int i = 0; i < n; i++)
    {
        ll x; char c; cin >> x >> c;
        if (c == 'R') p[0].push_back(x);
        else p[1].push_back(x);
    }

    sort(p[0].begin(), p[0].end()); sort(p[1].begin(), p[1].end());

    ll low = 0, hi = 1e9 + 5;
    while (low <= hi)
    {
        ll mid = (low + hi) / 2;
        cerr << mid << '\n';

        bool ok = 1;
        bool color = 0;
        int lst = (p[color].empty() ? -1 : p[color][0]);

        auto oper = [&]() -> void
        {
            for (int i = 1; i < k; i++)
            {
                cerr << color << ' ' << lst << '\n';
                auto valid = lower_bound(p[!color].begin(), p[!color].end(), lst + mid);

                if (valid == p[!color].end())
                {
                    ok = 0;
                    break;
                }

                color = !color;
                lst = *valid;
            }
        };

        if (lst == -1) ok = 1;
        else oper();
        bool ok1 = ok;

        ok = 1;
        color = 1;
        lst = (p[color].empty() ? -1 : p[color][0]);

        if (lst == -1) ok = 1;
        else oper();
        bool ok2 = ok;

        cerr << "ok: " << ok1 << ' ' << ok2 << '\n';
        if (ok1 || ok2) low = mid + 1;
        else hi = mid - 1;
    }

    cout << (low == 1e9 + 5 + 1 ? -1 : low - 1);
}