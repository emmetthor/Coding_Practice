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
    
    int dice[3][6] = {};
    for (int i = 0; i < 3; i++) for (int j = 0; j < 6; j++) cin >> dice[i][j];

    int match = 0;
    for (int i = 0; i < 6; i++) for (int j = 0; j < 6; j++) for (int k = 0; k < 6; k++) {
        set<int> res;
        res.insert(dice[0][i]);
        res.insert(dice[1][j]);
        res.insert(dice[2][k]);

        if (res == set{4, 5, 6}) {
            match++;
        }
    }

    cout << fixed << setprecision(8) << (double)match / 216.0;
}