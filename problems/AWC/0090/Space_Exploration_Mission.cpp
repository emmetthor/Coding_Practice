/*
Date: 2026-06-12

Tags: implementation
Independent: 5
Understanding: 4 
Implementation: 4
Recognition: 5

Mistakes: reading_misunderstanding
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
    
    ll l, n, c; cin >> l >> n >> c;
    ll lst = 0;
    ll curr_batery = c;
    while (n--)
    {
        ll p, w; cin >> p >> w;
        curr_batery -= p - lst;

        if (curr_batery < 0)
        {
            cout << -1;
            return 0;
        }

        curr_batery += w;
        curr_batery = min(c, curr_batery);

        lst = p;
    }

    curr_batery -= l - lst;

    if (curr_batery < 0)
    {
        cout << -1;
        return 0;
    }

    cout << curr_batery;
}