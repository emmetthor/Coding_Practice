/*
Date: 2026-07-01
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
    ll pos;
    for (int i = 0; i < k; i++)
    {
        cin >> pos;
    }

    cout << pos - 1;
}