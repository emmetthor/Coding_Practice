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
#include <iterator>
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
    vector<int> a(n + 1); for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> prefix(n + 1); for (int i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + a[i];
    vector<int> prefix_min(n + 1, 1e9); for (int i = 1; i <= n; i++) prefix_min[i] = min(prefix_min[i - 1], prefix[i]);
    vector<int> suffix_min(n + 2, 1e9); for (int i = n; i >= 1; i--) suffix_min[i] = min(suffix_min[i + 1], prefix[i]);

    auto sum = [&](int l, int r) -> int
    {
        if (l > r) return 0;
        return prefix[r] - prefix[l - 1];
    };

    while (q--)
    {
        int l, r; cin >> l >> r;

        int front_min = prefix_min[l - 1];
        int back_min = suffix_min[r + 1] - sum(1, r);

        cerr << front_min << ' ' << back_min << '\n';

        if (front_min >= 0 && sum(1, r) >= 0 && sum(1, r) + back_min >= 0) cout << "YES\n";
        else cout << "NO\n";
    }
}