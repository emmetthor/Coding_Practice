// original code
// // Date: 2026-04-25
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
//     string s; cin >> s;

//     // [l, r]
//     auto dc = [&](auto self, int l, int r) -> ll {
//         if (l > r) return 0;
//         if (l == r) return 0;

//         int mid = (l + r) / 2;

//         // [l, mid], [mid + 1, r]
//         ll res1 = self(self, l, mid);
//         ll res2 = self(self, mid + 1, r);
//         cerr << "range [" << l << ", " << mid << "] = " << res1 << '\n';
//         cerr << "range [" << mid + 1 << ", " << r << "] = " << res2 << '\n';
//         ll res = res1 + res2;

//         unordered_map<int, int> match_a, match_b, match_c;
//         map<array<int, 2>, int> match_ab, match_bc, match_ca;
//         map<array<int, 3>, int> match_abc;

//         array<int, 3> cnts = {};
//         for (int i = mid + 1; i <= r; i++) {
//             if (s[i] == 'A') cnts[0]++;
//             if (s[i] == 'B') cnts[1]++;
//             if (s[i] == 'C') cnts[2]++;

//             int a = cnts[0] - cnts[1];
//             int b = cnts[1] - cnts[2];
//             int c = cnts[2] - cnts[0];

//             cerr << "left: " << a << ' ' << b << ' ' << c << '\n';

//             match_a[a]++; match_b[b]++; match_c[c]++;
//             match_ab[{a, b}]++; match_bc[{b, c}]++; match_ca[{c, a}]++;
//             match_abc[{a, b, c}]++;
//         }

//         cnts[0] = cnts[1] = cnts[2] = 0;

//         for (int i = mid; i >= l; i--) {
//             ll invalid = 0;
//             if (s[i] == 'A') cnts[0]++;
//             if (s[i] == 'B') cnts[1]++;
//             if (s[i] == 'C') cnts[2]++;

//             int a = cnts[0] - cnts[1];
//             int b = cnts[1] - cnts[2];
//             int c = cnts[2] - cnts[0];

//             cerr << a << ' ' << b << ' ' << c << '\n';

//             invalid += match_a[-a] + match_b[-b] + match_c[-c] - match_ab[{-a, -b}] - match_bc[{-b, -c}] - match_ca[{-c, -a}] + match_abc[{-a, -b, -c}];

//             cerr << "when i = " << i << ", invalid = " << invalid << '\n';
//             res += r - (mid + 1) + 1 - invalid;
//         }

//         cerr << '\n';
//         return res;
//     };

//     cout << dc(dc, 0, n - 1);
// }

// better code
// Date: 2026-04-26
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
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    string S;
    cin >> N >> S;

    ll total = 1LL * N * (N + 1) / 2;

    auto count_one = [&](int x, int y) -> ll {
        map<int, ll> mp;
        mp[0] = 1;

        int cnt[3] = {};
        ll res = 0;

        for (char ch : S) {
            if (ch == 'A') cnt[0]++;
            if (ch == 'B') cnt[1]++;
            if (ch == 'C') cnt[2]++;

            int v = cnt[x] - cnt[y];
            res += mp[v];
            mp[v]++;
        }

        return res;
    };

    auto count_all_equal = [&]() -> ll {
        map<pair<int, int>, ll> mp;
        mp[{0, 0}] = 1;

        int cnt[3] = {};
        ll res = 0;

        for (char ch : S) {
            if (ch == 'A') cnt[0]++;
            if (ch == 'B') cnt[1]++;
            if (ch == 'C') cnt[2]++;

            pair<int, int> v = {
                cnt[0] - cnt[1],
                cnt[0] - cnt[2]
            };

            res += mp[v];
            mp[v]++;
        }

        return res;
    };

    ll AB = count_one(0, 1);
    ll AC = count_one(0, 2);
    ll BC = count_one(1, 2);
    ll ABC = count_all_equal();

    ll ans = total - AB - AC - BC + 2 * ABC;
    cout << ans << '\n';
}