/*
Date: 2026-07-31

Tags:
Independent:
Understanding:
Implementation:
Recognition:

Mistakes:
*/
#include <bits/stdc++.h>
#include <cstring>
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
    
    const int COLOR = 50;

    int n, q; cin >> n >> q;

    int pos[COLOR];
    for (int i = 1; i <= COLOR; i++) pos[i] = 1e9;
    for (int i = 1; i <= n; i++)
    {
        int ai; cin >> ai;
        pos[ai] = min(pos[ai], i);
    }

    while (q--)
    {
        int t; cin >> t;
        cout << pos[t] << " \n"[q == 0];
        for (int i = 1; i <= COLOR; i++)
        {
            if (i == t) continue;
            if (pos[i] < pos[t]) pos[i]++;
        }
        pos[t] = 1;
    }
}