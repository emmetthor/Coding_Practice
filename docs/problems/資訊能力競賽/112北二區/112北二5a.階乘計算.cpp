/*
Date: 2026-07-27

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
    
    int n; cin >> n;

    vector<bool> p(n + 1, 1);
    p[0] = p[1] = 0;
    for (int i = 2; i * i <= n; i++)
    {
        for (int j = i + i; j <= n; j += i) p[j] = 0;
    }
    vector<ll> prime_list;
    for (int i = 2; i <= n; i++) if (p[i]) 
    {
        prime_list.push_back(i);
        cerr << i << ' ';
    }
    cerr << '\n';

    vector<ll> ans;

    for (auto pp : prime_list)
    {
        ll res = 0;
        for (ll i = pp; i <= n; i *= pp)
        {
            res += n / i;
        }
        ans.push_back(res);
    }

    for (auto i : ans) cerr << i << ' '; cerr << '\n';

    int sz = ans.size();
    for (int i = 0, j = 0; i < sz; i = j)
    {
        while (j < sz && ans[i] == ans[j]) j++;

        if (j - i > 1) cout << j - i << '*' << ans[i];
        else cout << ans[i];
        cout << " \n"[i == sz - 1];
    }
}