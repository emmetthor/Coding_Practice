// Date: 2026-04-04
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
    
    int h, w; cin >> h >> w;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i == 0) cout << '#';
            else if (i == h - 1) cout << '#';
            else if (j == 0) cout << '#';
            else if (j == w - 1) cout << '#';
            else cout << '.';
        }
        cout << '\n';
    }
}