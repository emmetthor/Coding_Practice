/*
Date: 2026-06-10
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
    
    int n, k; cin >> n >> k;
    vector<int> a(n); for (auto &i : a) cin >> i;

    sort(a.begin(), a.end());

    int ans = 0;
    int lst_min = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] - lst_min > k)
        {
            ans++;
            lst_min = a[i];
        }
    }
    cout << ans + 1;
}