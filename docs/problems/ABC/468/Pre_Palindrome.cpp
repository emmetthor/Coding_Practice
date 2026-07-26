/*
Date: 2026-07-25

Tags: palindrome_problems
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
    
    string s; cin >> s;
    int n = s.size();

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        bool changed = 0;
        for (int d = 0; i + d < n && i - d >= 0; d++)
        {
            int l = i - d, r = i + d;
            cerr << l << ' ' << r << '\n';
            if (s[l] == s[r])
            {
                ans++;
            }
            else if (changed == 0)
            {
                ans++;
                changed = 1;
            }
            else break;
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        bool changed = 0;
        for (int d = 0; i + 1 + d < n && i - d >= 0; d++)
        {
            int l = i - d, r = i + 1 + d;
            cerr << l << ' ' << r << '\n';
            if (s[l] == s[r])
            {
                ans++;
            }
            else if (changed == 0)
            {
                ans++;
                changed = 1;
            }
            else break;
        }
    }

    cout << ans;

    // auto dfs = [&](auto self, int l, int r, bool changed) -> ll
    // {
    //     if (l > r) return 0;
    //     if (l == r) return 1;
    //     if (l + 1 == r && s[l] == s[r]) return 2;

    //     ll res = 0;

    //     if (s[l] == s[r])
    //         res = max(res, self(self, l + 1, r - 1, changed) + 2);

    //     else if (changed == 0)
    //         res = max(res, self(self, l + 1, r - 1, 1) + 2);

    //     res = max({res, self(self, l + 1, r, changed), self(self, l, r - 1, changed)});

    //     return res;
    // };

    // cout << dfs(dfs, 0, n - 1, 0);
}