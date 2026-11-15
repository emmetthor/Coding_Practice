/*
Date: 2026-11-07

Tags: fenwick_tree, discretization
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

const ll MOD = 1e9 + 7;

struct BIT
{
    int n;
    vector<ll> b;

    BIT(int _n) : n(_n), b(_n + 1) {};

    void update(int p, ll v)
    {
        for (; p <= n; p += p & -p)
            b[p] = (b[p] + v) % MOD;
    }

    ll prefix(int p)
    {
        ll res = 0;
        for (; p >= 1; p -= p & -p)
            res = (res + b[p]) % MOD;
        return res;
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n; cin >> n;
    BIT bit(n);
    vector<ll> a(n); for (auto &i : a) cin >> i;

    vector<ll> d = a;
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());
    auto get_id = [&](ll v) -> int
    {
        return lower_bound(d.begin(), d.end(), v) - d.begin();
    };

    ll ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        ll num = get_id(a[i]) + 1;
        cerr << "current: " << a[i] << " | " << bit.prefix(num - 1) << '\n';
        ans = (ans + (bit.prefix(num - 1) * a[i]) % MOD) % MOD;
        bit.update(num, a[i]);
    }

    cout << ans;
}