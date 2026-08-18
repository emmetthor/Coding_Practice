/*
Date: 2026-08-16

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
    
    string s; cin >> s;
    int n = s.size();

    vector<int> prefix6(n + 1);
    for (int i = 1; i <= n; i++)
    {
        prefix6[i] = prefix6[i - 1] + (s[i - 1] == '6' ? 1 : 0);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '7')
        {
            ans += prefix6[i + 1];
        }
    }

    cout << ans;
}