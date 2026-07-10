// Date: 2026-05-31
/*
Tags: modulo
Independent: 5
Understanding: 5
Implementation: 5
Recognition: 5
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
    
    int n, m; cin >> n >> m;

    int res = n % m;
    int cnt = 1;
    while (res > 0)
    {
        m = res;
        res = n % m;
        cnt++;
    }

    cout << cnt;
}