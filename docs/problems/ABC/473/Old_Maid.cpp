/*
Date: 2026-08-29
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
    vector<int> cnt(150);
    for (int i = 0; i < n; i++)
    {
        int ai; cin >> ai;
        cnt[ai]++;
    } 

    int ans = 0;
    for (int i = 0; i <= 100; i++)
    {
        if (cnt[i] % 2 == 1) ans += i;
    }

    cout << ans;
}