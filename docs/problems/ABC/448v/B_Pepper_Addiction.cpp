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
    
    int n, m; cin >> n >> m;
    vector<int> pepper(m + 1); for (int i = 1; i <= m; i++) cin >> pepper[i];

    ll ans = 0;
    while (n--) {
        int a, b; cin >> a >> b;

        ans += min(pepper[a], b);
        pepper[a] -= min(pepper[a], b);
    }

    cout << ans;
}