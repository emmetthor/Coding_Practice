// Date: 2026-05-02
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

    const int MOD = 998244353;
    
    string s; cin >> s;
    int n = s.size();

    ll ans = 0;
    for (int i = 0, j = 1; i < n;) {
        while (j < n && s[j - 1] != s[j]) j++;
        ans += 1ll * (j - i + 1) * (j - i) / 2;

        i = j;
        j++;
    }

    cout << ans % MOD;
}