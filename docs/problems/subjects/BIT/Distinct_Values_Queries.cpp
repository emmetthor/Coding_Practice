/*
Date: 2026-07-19

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

struct BIT
{
    int n;
    vector<int> a;

    BIT (int _n) : n(_n), a(_n + 1) {};

    void add(int x, int v)
    {
        for (int i = x; i <= n; i += i & -i)
        {
            a[i] += v;
        }
    }

    int prefix(int x)
    {
        int res = 0;
        for (int i = x; i >= 1; i -= i & -i)
        {
            res += a[i];
        }
        return res;
    }

    int sum(int l, int r)
    {
        return prefix(r) - prefix(l - 1);
    }
};

struct Query
{
    int id = 0;
    int left = 0;
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n, q; cin >> n >> q;

    vector<int> a(n + 1); for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<Query>> qq(n + 1); for (int i = 0; i < q; i++)
    {
        int l, r; cin >> l >> r;
        qq[r].push_back({i, l});
    }

    map<int, int> lst;
    BIT bit(n);
    vector<int> ans(q);

    for (int i = 1; i <= n; i++)
    {
        if (lst.find(a[i]) != lst.end())
        {
            cerr << "appeared\n";
            bit.add(lst[a[i]], -1);
        }
        lst[a[i]] = i;
        bit.add(i, 1);

        for (auto [id, l] : qq[i])
        {
            ans[id] = bit.sum(l, i);
        }
    }

    for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}