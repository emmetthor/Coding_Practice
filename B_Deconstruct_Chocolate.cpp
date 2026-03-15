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
    
    int h, w, q; cin >> h >> w >> q;

    while (q--) {
        int t, x; cin >> t >> x;
        if (t == 1) {
            cout << x * w << '\n';
            h -= x;
        } else {
            cout << x * h << '\n';
            w -= x;
        }
    }
}