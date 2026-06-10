/*
Date: 2026-06-10
*/
#include <bits/stdc++.h>
#include <unordered_map>
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
    
    int n, q; cin >> n >> q;
    string stone; cin >> stone;

    vector<ll> white_prefix(n + 1), black_prefix(n + 1);
    for (int i = 1; i <= n; i++)
    {
        white_prefix[i] += white_prefix[i - 1] + (stone[i - 1] == 'W' ? 1 : 0);
        black_prefix[i] += black_prefix[i - 1] + (stone[i - 1] == 'B' ? 1 : 0);
    }

    for (int i = 0; i <= n; i++) cerr << white_prefix[i] << ' ';
    cerr << '\n';
    for (int i = 0; i <= n; i++) cerr << black_prefix[i] << ' ';
    cerr << '\n';

    unordered_map<int, int> diff;
    vector<ll> ans(n + 2);
    vector<ll> ans_prefix(n + 2);

    for (int r = 1, l = 1; r <= n; r++)
    {
        while ()
    }

    while (q--)
    {
        int l, r; cin >> l >> r;
        cout << ans[l] - ans[r + 1] << '\n';
    }
}