// Date: 2026-05-31
/*
Tags: same_side_two_pointer
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
    
    int n, m; cin >> n >> m;

    vector<int> a(n), b(m); for (auto &i : a) cin >> i; for (auto &i : b) cin >> i;

    sort(a.begin(), a.end(), greater<>()); sort(b.begin(), b.end(), greater<>());

    int cnt = 0;
    for (int i = 0, j = 0; i < n; i++)
    {
        while (j < m && b[j] > 2 * a[i]) j++;
        if (j < m && b[j] <= 2 * a[i]) cnt++;
        j++;
    }

    cout << cnt;
}