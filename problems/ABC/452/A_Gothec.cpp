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
    
    map<pair<int, int>, bool> festival = {
        {{1, 7}, 1},
        {{3, 3}, 1},
        {{5, 5}, 1},
        {{7, 7}, 1},
        {{9, 9}, 1}
    };

    int m, d; cin >> m >> d;

    cout << (festival[{m, d}] == 1 ? "Yes" : "No");
}