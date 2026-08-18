/*
Date: 2026-08-17

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

    const ll INF = 1e18;
    
    int n, k; cin >> n >> k;

    vector<ll> c(n + 1); for (int i = 1; i <= n; i++) cin >> c[i];

    deque<ll> stk;
    vector<ll> dp(n + 1, -INF);
    dp[1] = c[1];
    stk.push_back(c[1]);

    for (int i = 2; i <= n; i++)
    {
        cerr << "doing " << i << '\n';
        if (stk.size() && i - k - 1 >= 1 && stk.front() == dp[i - k - 1]) stk.pop_front();

        ll ma = stk.front();
        ll res = ma + c[i];

        while (stk.size() && stk.back() < res) stk.pop_back();

        stk.push_back(res);
        dp[i] = res;
    }

    cout << dp[n];
}