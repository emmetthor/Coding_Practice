/*
Date: 2026-07-04

Tags: different_side_two_pointer
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
    
    int n; string s; cin >> n >> s;

    vector<int> ans(n);
    for (int i = 0; i < n; i++) ans[i] = i + 1;

    int l = 0, r = n - 1;
    int nxt_side = 1; // 0: left; 1: right
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == 'o')
        {
            nxt_side ^= 1;
        }

        if (nxt_side == 0)
        {
            ans[l++] = i + 1;
        }
        else
        {
            ans[r--] = i + 1;
        }
    }

    for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
}