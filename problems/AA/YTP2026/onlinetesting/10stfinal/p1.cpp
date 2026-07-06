/*
Date: 2026-07-05

Tags:
Independent:
Understanding:
Implementation:
Recognition:

Mistakes:
*/
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

    vector<vector<int>> table(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n / 2; j++)
        {
            table[i][(i + j) % n] = 1;
        }
    }

    auto solve = [&]() -> void
    {
        int x, y, z; cin >> x >> y >> z;
        x--; y--; z--;

        for (int i = 0; i < n; i++)
        {
            if (table[i][x] == 1 && table[i][y] == 1 && table[i][z] == 1)
            {
                cout << i + 1 << '\n';
                return;
            }
        }

        cout << -1 << '\n';
    };

    while (q--) solve();
}