/*
Date: 2026-07-04
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
    
    int x, y, l, r, a, b; cin >> x >> y >> l >> r >> a >> b;

    int fee[30] = {};

    for (int i = 1; i <= 23; i++)
    {
        if (l <= i && i < r) fee[i] = x;
        else fee[i] = y;
    }

    int ans = 0;
    for (int i = a; i < b; i++)
    {
        ans += fee[i];
        cerr << fee[i] << ' ';
    }

    cout << ans;
}