/*
Date: 2026-08-08

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
    vector<vector<int>> a(2, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) cin >> a[0][i];
    for (int i = 1; i <= n; i++) a[1][a[0][i]] = i;

    for (int i = 1; i <= n; i++) cerr << a[0][i] << " \n"[i == n];
    for (int i = 1; i <= n; i++) cerr << a[1][i] << " \n"[i == n];

    int it1 = 0, it2 = 1;
    while (q--)
    {
        auto &ori = a[it1], &pos = a[it2];
        int type; cin >> type;
        if (type == 1)
        {
            int x, y; cin >> x >> y;
            swap(pos[ori[x]], pos[ori[y]]);
            swap(ori[x], ori[y]);   
        }
        else if (type == 2)
        {
            swap(it1, it2);
        }
    }

    for (int i = 1; i <= n; i++) cout << a[it1][i] << " \n"[i == n];
}