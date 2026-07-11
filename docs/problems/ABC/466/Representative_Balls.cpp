/*
Date: 2026-07-11
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
    
    int n, m; cin >> n >> m;

    vector<int> ma_ball(m + 1, -1);
    for (int i = 0; i < n; i++)
    {
        int c, s; cin >> c >> s;
        ma_ball[c] = max(ma_ball[c], s);
    }

    for (int i = 1; i <= m; i++) cout << ma_ball[i] << " \n"[i == m];
}