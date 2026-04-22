// Date: 2026-04-18
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
    
    int t; cin >> t;

    auto solve = [&]() {
        int n, a, b; cin >> n >> a >> b;

        if (n & 1 || ((a + b) & 1) == 0) { cout << "No\n"; return; }

        for (int i = 1; i < a - 1; i++) {
            for (int j = 1; j <= n; j++) {

            }
        }

        for (int )
    };

    while (t--) solve();
}