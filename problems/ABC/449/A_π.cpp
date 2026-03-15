// Date: 2026-03-14
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    bool debug_mode = 1;
#else
    bool debug_mode = 0;
#endif

using ll = long long;
using ull = unsigned ll;

#define rep(i, st, ed) for (int i = (st); i < (ed); i++)
#define all(x) x.begin(), x.end()
#define cerr if(debug_mode) cerr

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    double pi = 3.141592653589793;
    double n; cin >> n;
    cout << fixed << setprecision(20) << pi * (n / 2.0) * (n / 2.0);
}