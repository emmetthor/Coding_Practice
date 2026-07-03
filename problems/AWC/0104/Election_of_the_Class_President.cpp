/*
Date: 2026-07-02

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
    vector<int> a(n); for (auto &i : a) cin >> i;

    int ma = *max_element(a.begin(), a.end());

    int cnt = 0;
    int pos = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == ma) {
            cnt++;
            pos = i + 1;
        }
    }

    cout << (cnt == 1 ? pos : -1);
}