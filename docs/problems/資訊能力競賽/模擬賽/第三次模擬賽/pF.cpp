/*
Date: 2026-10-17

Tags:
Independent:
Understanding:
Implementation:
Recognition:

Mistakes:
*/
#pragma GCC optimize("O3, unroll-loops")  
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    bool debug_mode = 1;
#else
    bool debug_mode = 0;
#endif

using ll = long long;
#define cerr if(debug_mode) cerr

struct BIT
{
    int n;
    vector<ll> b;

    BIT(int _n) : n(_n), b(_n + 1) {};

    void update(int p, ll v)
    {
        for (; p <= n; p += p & -p) b[p] += v;
    }

    ll prefix(int p)
    {
        ll res = 0;
        for (; p >= 1; p -= p & -p) res += b[p];
        return res;
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n; cin >> n;
    vector<ll> a(n); for (auto &i : a) cin >> i;
    sort(a.begin(), a.end());

    vector<ll> items;
    for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) items.push_back(a[i] + a[j]);
    for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) items.push_back(a[j] - a[i]);
    for (int i = 0; i < n; i++) items.push_back(a[i]);

    sort(items.begin(), items.end());
    items.erase(unique(items.begin(), items.end()), items.end());

    auto get_id = [&](ll v)
    {
        return lower_bound(items.begin(), items.end(), v) - items.begin() + 1;
    };

    ll ans = 0;
    BIT bit(items.size() + 5);
    for (ll m = 2; m < n; m++)
    {
        for (ll l = 0; l < m - 1; l++)
        {
            bit.update(get_id(a[l] + a[m - 1]), +1);
        }

        for (ll r = m + 1; r < n; r++)
        {
            int e2 = a[m], e3 = a[r];
            ans += m * (m - 1) / 2 - bit.prefix(get_id(e3 - e2));
        }
    }

    cout << ans;

    // ll ans = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         for (int k = j + 1; k < n; k++)
    //         {
    //             for (int l = k + 1; l < n; l++)
    //             {
    //                 ll e1 = a[i] + a[j], e2 = a[k], e3 = a[l];
    //                 if (e3 - e2 < e1) ans++;
    //             }
    //         }
    //     }
    // }
    // cout << ans;
}