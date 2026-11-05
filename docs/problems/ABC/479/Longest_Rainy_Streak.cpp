/*
Date: 2026-10-11
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

    int curr = 0;
    int longest = 0;
    for (int i = 0; i < n; i++)
    {
        char c; cin >> c;
        if (c == 'R') curr++;
        else if (c == 'S')
        {
            curr = 0;
        }
        longest = max(longest, curr);
    }

    cout << longest;
}