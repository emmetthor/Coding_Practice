/*
Date: 2026-07-01
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

    ll a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        ll _a, _b; cin >> _a >> _b;
        a += _a;
        b += _b;
    }

    cout << min(a, b);
}