/*
Date: 2026-07-23

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
    vector<int> a(n), b(n); for (auto &i : a) cin >> i; for (auto &i : b) cin >> i;

    int a_win = 0, b_win = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > b[i]) a_win++;
        else b_win++;
    }

    int ev_a_w = 0, ev_b_w = 0;

    for (int diff = 1; diff < n; diff++)
    {
        int aw = 0, bw = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[(i + diff) % n] > b[i]) aw++;
            else bw++;
        }

        if (aw > bw) ev_a_w++;
        else ev_b_w++;
    }

    if (ev_a_w && b_win > a_win) cout << 'X';
    else if (ev_b_w && a_win > b_win) cout << 'X';
    else if (a_win > b_win) cout << 'A';
    else cout << 'B';
}