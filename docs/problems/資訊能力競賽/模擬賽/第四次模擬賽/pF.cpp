/*
Date: 2026-10-24

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
    
    int n; ll m; cin >> n >> m;
    vector<ll> c(n); for (auto &i : c) cin >> i;
    vector<ll> ans(n);

    ll left = m / 2 + (m % 2 == 1);
    ll right = m - left;

    for (int i = 0; i < n; i++)
    {
        if (ans[i] + left > c[i])
        {
            ans[i] += c[i];
            left -= c[i];
        }
        else
        {
            ans[i] += left;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (ans[i] + right > c[i])
        {
            ans[i] += c[i];
            right -= c[i];
        }
        else
        {
            ans[i] += right;
            break;
        }
    }

    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
}