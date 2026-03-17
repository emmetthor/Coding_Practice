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
    
    int n, q; cin >> n >> q;
    vector<int> value(n + 1); for (int i = 1; i <= n; i++) cin >> value[i];

    set<pair<int, int>> balls;
    for (int i = 1; i <= n; i++) {
        balls.insert({value[i], i});
    }

    while (q--) {
        int k; cin >> k;
        vector<int> remove(k); for (int i = 0; i < k; i++) cin >> remove[i];

        for (auto i : remove) {
            balls.erase({value[i], i});
        }

        cout << balls.begin() -> first << '\n';

        for (auto i : remove) {
            balls.insert({value[i], i});
        }
    }
}