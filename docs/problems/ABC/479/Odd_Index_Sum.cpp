/*
Date: 2026-10-11
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
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int ai; cin >> ai;
        if (i % 2 == 1) sum += ai;
    }

    cout << sum;
}