/*
Date: 2026-06-11
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
    ll sum = 0;
    vector<ll> a(n); for (auto &i : a)
    {
        cin >> i;
        sum += i;
    }

    while (q--)
    {
        int d; cin >> d;
        cout << sum - a[d - 1] << '\n';
        sum -= a[d - 1];
    }
}