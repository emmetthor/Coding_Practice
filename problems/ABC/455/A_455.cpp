// Date: 2026-04-25
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
    
    int a, b, c; cin >> a >> b >> c;

    cout << (a != b && b == c ? "Yes" : "No");
}