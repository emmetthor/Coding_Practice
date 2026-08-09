/*
Date: 2026-08-08

Tags:
Independent:
Understanding:
Implementation:
Recognition:

Mistakes:
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
    
    int n; cin >> n;
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++)
    {
        int c; cin >> c; cnt[c]++;
    }

    cout << n - *max_element(cnt.begin(), cnt.end());
}