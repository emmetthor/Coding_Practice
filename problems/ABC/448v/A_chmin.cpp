// Date: 2026-03-15
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
    
    int n, x; cin >> n >> x;
    for (int i = 0; i < n; i++) {
        int ai; cin >> ai;
        if (ai < x) {
            x = ai;
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
}