/*
Date: 2026-07-05

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
    
    ll n, a, b, c; cin >> n >> a >> b >> c;

    cout << max(0ll, min({a, b, c}) + n - max({a, b, c}) + 1ll);
}