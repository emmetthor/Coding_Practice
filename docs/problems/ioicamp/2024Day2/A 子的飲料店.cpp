/*
Date: 2026-07-30

Tags: equation_optimize
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

struct BIT
{
    int n;
    vector<ll> b;

    BIT (int _n) : n(_n), b(_n + 1) {};

    void add(int x, ll v)
    {
        for (; x <= n; x += x & -x)
        {
            b[x] += v;
        }
    }

    ll sum(int x)
    {
        ll res = 0;
        for (; x >= 1; x -= x & -x)
        {
            res += b[x];
        }
        return res;
    }

    ll sum(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n; cin >> n;
    BIT bit_sum(n), bit_square_sum(n);
    
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        bit_sum.add(i, a[i]);
        bit_square_sum.add(i, a[i] * a[i]);
    }

    int q; cin >> q;
    while (q--)
    {
        int type; cin >> type;
        if (type == 1)
        {
            int p; ll x; cin >> p >> x;

            bit_sum.add(p, -a[p] + x);
            bit_square_sum.add(p, -(a[p] * a[p]) + x * x);
            a[p] = x;
        }
        else
        {
            int l, r; cin >> l >> r;
            ll sum = bit_sum.sum(l, r);
            ll square_sum = bit_square_sum.sum(l, r);

            cout << (sum * sum - square_sum) / 2 << '\n';
        }
    }
}