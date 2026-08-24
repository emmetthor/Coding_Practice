/*
Date: 2026-08-22

Tags:sliding_window
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
    
    int n, m; ll k; cin >> n >> m >> k;
    vector<ll> food(n); for (auto &i : food) cin >> i;

    deque<int> stk;
    ll total_cal = 0;
    for (int i = 0; i < n; i++)
    {
        int should_delete = i - m;
        if (stk.size() && stk.front() == should_delete)
        {
            total_cal -= food[stk.front()];
            stk.pop_front();
        }

        if (total_cal + food[i] <= k)
        {
            stk.push_back(i);
            total_cal += food[i];

            cout << "Yes\n";
        }
        else cout << "No\n";
    }
}