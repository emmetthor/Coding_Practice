// Date: 2026-04-04

// 解法：
// 由排容原理可知，可以計算全部的子字串個數再減去：有包含 T 的子字串個數及可
// 若要包含 T，則此子字串可以是：已經有 T 的最小子字串再延伸而來，
// 因此只需固定左界，盡量找最靠左的右界，就可以計算出所有左界在 l 的含 T 子字串個數
// 由於 | T | 很小，使用 upper bound 一直找最近的 T_i 就可以快速推出右界

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
    
    string s, t; cin >> s >> t;

    int n = s.size(), m = t.size();
    
    vector<vector<int>> pos(30);

    for (int i = 0; i < n; i++) {
        pos[s[i] - 'a'].emplace_back(i);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int curr = i - 1;

        bool valid = 1;
        for (int j = 0; j < m; j++) {
            auto &arr = pos[t[j] - 'a'];
            auto it = upper_bound(arr.begin(), arr.end(), curr);

            if (it == arr.end()) {
                valid = 0;
                break;
            }

            curr = *it;
        }

        if (valid) {
            ans += curr - i;
        } else {
            ans += n - i;
        }
    }

    cout << ans;
}