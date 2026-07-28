/*
Date: 2026-07-27

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
    
    int n; cin >> n;

    vector<array<int, 2>> domino(n); for (auto &[x, h] : domino) cin >> x >> h;

    for (int i = 1; i < n; i++)
    {
        auto [x1, h1] = domino[i - 1];
        auto [x2, h2] = domino[i];

        int dis = x2 - x1;

        if (4 * dis * dis + h2 * h2 <= 4 * h1 * h1)
        {
            continue;
        }
        else
        {
            cout << x2;
            return 0;
        }
    }

    cout << -1;
}