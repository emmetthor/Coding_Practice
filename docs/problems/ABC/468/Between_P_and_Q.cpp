/*
Date: 2026-07-25

Tags: permutation
Independent: 5
Understanding: 5
Implementation: 5
Recognition: 5
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
    vector<int> p(n), q(n); for (auto &i : p) cin >> i; for (auto &i : q) cin >> i;
    vector<int> a(n); for (int i = 1; i <= n; i++) a[i - 1] = i;

    if (p == q)
    {
        cout << 0;
        return 0;
    }

    int state = 0;
    int ans = 0;
    do
    {
        if (a == p) state = 1;

        if (state == 1) ans++;

        if (a == q) state = 2;
    }
    while (next_permutation(a.begin(), a.end()));

    cout << (state == 2 ? ans - 2 : 0);
}