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
    
    int n, m; cin >> n >> m;

    vector<int> friends(n); for (auto &i : friends) cin >> i;
    sort(friends.begin(), friends.end());
    
    vector<int> forbid(m); for (auto &i : forbid) cin >> i;

    for (auto i : forbid)
    {
        auto it = upper_bound(friends.begin(), friends.end(), i);

        if (it != friends.begin() && it != friends.end())
        {
            cout << -1;
            return 0;
        }
    }

    int meet = -1;
    if (n % 2 == 0)
    {
        meet = (friends[n / 2 - 1] + friends[n / 2]) / 2;
    } 
    else
    {
        meet = friends[n / 2];
    }

    ll ans = 0;
    for (auto i : friends) ans += abs(i - meet);

    cout << ans;
}