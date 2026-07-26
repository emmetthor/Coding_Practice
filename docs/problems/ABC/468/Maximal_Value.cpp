/*
Date: 2026-07-25
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
    vector<int> a(n); for (auto &i : a) cin >> i;

    int ans = 0;
    for (int i = 1; i < n - 1; i++) if (a[i - 1] < a[i] && a[i] > a[i + 1]) ans++;

    cout << ans;
}