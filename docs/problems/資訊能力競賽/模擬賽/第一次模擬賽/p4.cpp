/*
Date: 2026-07-12

Tags: 1d_prefix_sum
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
    
    int n, q; cin >> n >> q;

    vector<ll> p(n + 1); for (int i = 1; i <= n; i++) cin >> p[i];

    vector<ll> st(n + 1), hp(n + 1);
    for (int i = 2; i <= n; i++)
    {
        st[i] += st[i - 1];
        hp[i] += hp[i - 1];
        if (p[i] > p[i - 1])
        {
            st[i] += p[i] - p[i - 1];
        }
        else if (p[i] < p[i - 1])
        {
            hp[i] += p[i - 1] - p[i];
        }
    }

    for (int i = 1; i <= n; i++) cerr << st[i] << ' ';
    cerr << '\n';
    for (int i = 1; i <= n; i++) cerr << hp[i] << ' ';
    cerr << '\n';

    while (q--)
    {
        int l, r; cin >> l >> r;
        l++; r++;
        cout << st[r] - st[l] << ' ' << hp[r] - hp[l] << '\n';
    }
}