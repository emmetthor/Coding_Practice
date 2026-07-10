/*
Date: 2026-07-02

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
    
    int n, t; cin >> n >> t;

    if (t == 0)
    {
        cout << 0;
        return 0;
    }

    vector<int> bus(n); for (auto &i : bus) cin >> i;

    int ans = 2e9;

    for (auto i : bus)
    {
        ans = min(ans, i * (t / i + (t % i != 0)));
    }

    cout << ans;
}