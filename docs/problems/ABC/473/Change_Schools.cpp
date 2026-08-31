/*
Date: 2026-08-29
*/
#include <algorithm>
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
    
    int n, k; cin >> n >> k;
    vector<int> cnt(k + 1);
    for (int i = 0; i < n; i++)
    {
        int ai; cin >> ai;
        cnt[ai]++;
    }

    int ans = 0;
    int ma = *max_element(cnt.begin(), cnt.end());

    for (int i = 1; i <= k; i++)
    {
        if (cnt[i] == ma || cnt[i] == ma - 1) ans++;
    }

    cout << ans;
}