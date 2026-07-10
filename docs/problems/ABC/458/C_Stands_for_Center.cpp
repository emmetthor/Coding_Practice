// Date: 2026-05-16
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
    
    string s; cin >> s;
    int n = s.size();

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != 'C') continue;
        ll len = min(n - i, i + 1);

        ans += len;
    }

    cout << ans;
}