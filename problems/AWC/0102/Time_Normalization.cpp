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
    while (n--) {
        ll h, m; cin >> h >> m;

        h += m / 60;
        ll d = h / 24;
        
        cout << d << ' ' << h % 24 << ' ' << m % 60 << '\n';
    }
}