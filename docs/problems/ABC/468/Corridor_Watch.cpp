/*
Date: 2026-07-25

Tags: difference
Independent: 5
Understanding: 5
Implementation: 5
Recognition: 5

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
    
    int m, d; cin >> m >> d;
    string s; cin >> s;

    vector<int> diff(m + 1);
    for (int i = 0; i < m; i++)
    {
        if (s[i] == 'G')
        {
            diff[max(0, i - d)]++;
            diff[min(m, i + d + 1)]--;
        }
    }

    for (int i = 1; i < m; i++)
    {
        diff[i] += diff[i - 1];
    }

    for (int i = 0; i < m; i++) cerr << diff[i] << ' ';

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        ans += (diff[i] == 0 ? 1 : 0);
    }

    cout << ans;
}