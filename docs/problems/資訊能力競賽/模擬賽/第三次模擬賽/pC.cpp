/*
Date: 2026-10-17

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
    ll res = 0;
    for (int i = 0; i < n; i++){
        int l, r; cin >> l >> r;
        ll w; cin >> w;
        res += w;
    }

    cout << res * res;
}