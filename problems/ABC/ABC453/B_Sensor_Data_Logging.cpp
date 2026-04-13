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
    
    int t, x; cin >> t >> x;

    int lastSave = -10000;
    for (int i = 0; i < t + 1; i++) {
        int read; cin >> read;
        if (abs(read - lastSave) >= x)
        {
            cout << i << ' ' << read << '\n';
            lastSave = read;
        }
    }
}