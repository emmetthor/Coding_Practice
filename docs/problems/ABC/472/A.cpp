/*
Date: 2026-08-22
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
    
    string s; cin >> s;
    for (auto c : s)
    {
        if (c - 'A' == 0) cout << c;
        else cout << '.';
    }
}