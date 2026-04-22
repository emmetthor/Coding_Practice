// Date: 2026-04-11
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
    
    int n; cin >> n;

    vector<ll> l(n); for (auto& i : l) cin >> i;

    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        ll pos = 0;
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            ll newPos = -1;
            if ((i >> j) & 1) {
                newPos = pos + l[j];
            } else {
                newPos = pos - l[j];
            }

            if ((pos >= 0 && newPos < 0) || (pos < 0 && newPos >= 0))
            {
                cnt++;
            }
            
            pos = newPos;
        }

        ans = max(ans, cnt);
    }

    cout << ans;
}