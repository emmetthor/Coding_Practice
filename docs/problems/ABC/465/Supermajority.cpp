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
    
    int a, b; cin >> a >> b;

    cout << (3 * a > 2 * b ? "Yes" : "No");
}