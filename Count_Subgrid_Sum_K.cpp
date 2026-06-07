// Date: 2026-06-07
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
    
    int h, w, k; cin >> h >> w >> k;

    vector<string> mp(h); for (auto &s : mp) cin >> s;

    vector<vector<int>> prefix(h + 1, vector<int>(w + 1));

    auto get_sum = [&](int x1, int y1, int x2, int y2) -> int
    {
        return prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1];
    };

    for (int i = 1; i <= h; i++) for (int j = 1; j <= w; j++)
    {
        prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + (mp[i - 1][j - 1] == '1' ? 1 : 0);
    }

    ll ans = 0;
    vector<ll> cnt(h * w + 1);
    for (int top = 1; top <= h; top++) for (int bot = top; bot <= h; bot++)
    {
        vector<ll> used;
        ll curr_prefix = 0;
        cnt[0]++;
        used.push_back(0);

        for (int i = 1; i <= w; i++)
        {
            curr_prefix += get_sum(top, i, bot, i);

            int target = curr_prefix - k;
            if (0 <= target && target <= h * w) ans += cnt[target];

            cnt[curr_prefix]++;
            used.push_back(curr_prefix);
        }

        for (auto i : used) cnt[i]--;
    }

    cout << ans;
}

// // Date: 2026-06-06
// #include <bits/stdc++.h>
// #include <unordered_map>
// using namespace std;

// #ifdef LOCAL
//     bool debug_mode = 1;
// #else
//     bool debug_mode = 0;
// #endif

// using ll = long long;
// #define cerr if(debug_mode) cerr

// const int MA = 505;

// int main() {
//     cin.tie(0) -> sync_with_stdio(0);
    
//     int h, w, k; cin >> h >> w >> k;

//     vector<string> mp(h); for (auto &s : mp) cin >> s;

//     // If h > w, transpose grid so we square the smaller dimension.
//     if (h > w) {
//         vector<string> t(w, string(h, '0'));
//         for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) t[j][i] = mp[i][j];
//         mp.swap(t);
//         swap(h, w);
//     }

//     ll ans = 0;
//     vector<int> row_sums(w, 0);
//     for (int top = 0; top < h; ++top) {
//         fill(row_sums.begin(), row_sums.end(), 0);
//         for (int bot = top; bot < h; ++bot) {
//             for (int col = 0; col < w; ++col) row_sums[col] += (mp[bot][col] == '1');

//             // count subarrays of row_sums with sum == k
//             if (k == 0) {
//                 long long run = 0;
//                 for (int col = 0; col < w; ++col) {
//                     if (row_sums[col] == 0) ++run;
//                     else { ans += run * (run + 1) / 2; run = 0; }
//                 }
//                 ans += run * (run + 1) / 2;
//             } else {
//                 long long curr = 0;
//                 int l = 0, r = 0;
//                 while (l < w) {
//                     while (r < w && curr < k) curr += row_sums[r++];
//                     if (curr == k) {
//                         int t = r;
//                         while (t < w && row_sums[t] == 0) ++t;
//                         ans += 1 + (t - r);
//                         //r = t;
//                     }
//                     curr -= row_sums[l++];
//                 }
//             }
//         }
//     }

//     cout << ans;
// }