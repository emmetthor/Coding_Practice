// Date: 2026-03-22
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

    auto solve = []() -> void {
        int n; string s; cin >> n >> s;

        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == 'L') {
                cout << i << '\n';
                return;
            }
        }
    };

    while (t--) solve();
}