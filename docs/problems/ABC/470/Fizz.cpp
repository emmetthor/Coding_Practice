/*
Date: 2026-08-08

Tags:
Independent:
Understanding:
Implementation:
Recognition:

Mistakes:
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
    for (int i = 1; i <= n; i++)
    {
        if (i % 3 == 0) cout << "Fizz\n";
        else cout << i << '\n';
    }
}