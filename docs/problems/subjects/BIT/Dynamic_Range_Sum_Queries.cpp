/*
Date: 2026-07-18

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

template<typename T>
struct BIT
{
    int n;
    vector<T> a;

    BIT(int _n) : n(_n + 1), a(_n + 1) {};

    void add(int x, T v)
    {
        for (int i = x; i <= n; i += i & -i)
        {
            a[i] += v;
        }
    }

    T get_prefix(int x)
    {
        T res = 0;
        for (int i = x; i >= 1; i -= i & -i)
        {
            res += a[i];
        }
        return res;
    }

    T get_range(int l, int r)
    {
        return get_prefix(r) - get_prefix(l - 1);
    }

    void set(int x, T v)
    {
        T ori = get_range(x, x);
        cerr << "set " << x << ' ' << -ori << " + " << v << '\n';
        add(x, -ori + v);
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n, q; cin >> n >> q;

    BIT<ll> bit(n);

    for (int i = 1; i <= n; i++)
    {
        ll u; cin >> u;
        bit.set(i, u);
    }

    while (q--)
    {
        int type; cin >> type;
        if (type == 1)
        {
            int k; ll u; cin >> k >> u;
            bit.set(k, u);
        }
        else
        {
            int l, r; cin >> l >> r;
            cout << bit.get_range(l, r) << '\n';
        }
    }
}