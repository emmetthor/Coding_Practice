/*
Date: 2026-07-01

Tags: greedy
Independent: 5
Understanding: 3
Implementation: 5
Recognition: 5

Mistakes: wrong_greedy_choice
*/
// #include <bits/stdc++.h>
// using namespace std;

// #ifdef LOCAL
//     bool debug_mode = 1;
// #else
//     bool debug_mode = 0;
// #endif

// using ll = long long;
// #define cerr if(debug_mode) cerr

// int main() {
//     cin.tie(0) -> sync_with_stdio(0);
    
//     int n; cin >> n;
//     vector<ll> a(n); for (auto &i : a) cin >> i;

//     sort(a.begin(), a.end());

//     vector<ll> b(n);
//     int cnt = 0;
//     for (int i = 0; i <= n - i - 1; i++)
//     {
//         if (i == n - i - 1) b[cnt++] = a[i];
//         else
//         {
//             b[cnt++] = a[n - i - 1];
//             b[cnt++] = a[i];
//         }
//     }

//     ll l = b[0], r = b[0];
//     ll ans = 0;
//     for (int i = 1; i < n; i++)
//     {
//         cerr << b[i] << '\n';
//         if (abs(b[i] - l) > abs(b[i] - r))
//         {
//             ans += abs(b[i] - l);
//             l = b[i];
//         }
//         else
//         {
//             ans += abs(b[i] - r);
//             r = b[i];
//         }
//     }

//     cout << ans;
// }

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

    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    
    vector<ll> a(n); for (auto &i : a) cin >> i;

    sort(a.begin(), a.end());

    if (n % 2 == 0)
    {
        ll ans = 0;
        int m = n / 2;
        for (int i = 0; i < m; i++) ans -= 2 * a[i];
        for (int i = m; i < n; i++) ans += 2 * a[i];
        ans -= a[m];
        ans += a[m - 1];

        cout << ans;
    }
    else
    {
        ll ans = 0;
        int m = n / 2;
        for (int i = 0; i < m; i++) ans -= 2 * a[i];
        for (int i = m + 1; i < n; i++) ans += 2 * a[i];

        ans = max(ans - a[m] + a[m - 1], ans - a[m + 1] + a[m]);

        cout << ans;
    }
}