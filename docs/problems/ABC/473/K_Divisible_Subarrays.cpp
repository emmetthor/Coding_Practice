/*
Date: 2026-08-29

Tags: associative_containers, greedy, modulo, 1d_prefix_sum
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
    
    int n; ll k; cin >> n >> k;

    vector<ll> a(n + 1); for (int i = 1; i <= n; i++) cin >> a[i];
    vector<ll> prefix(n + 1); for (int i = 1; i <= n; i++) prefix[i] = (prefix[i - 1] + a[i]) % k;

    set<ll> pre;
    pre.insert(0);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (pre.insert(prefix[i]).second == false ||
            a[i] % k == 0
        )
        {
            ans++;
            pre.clear();
            pre.insert(prefix[i]);
        }
    }

    cout << ans;
}