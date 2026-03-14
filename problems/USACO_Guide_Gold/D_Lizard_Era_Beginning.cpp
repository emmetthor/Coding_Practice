/*
Tags: 折半枚舉, 位元

解法：直接折半枚舉所有可能
要確定是否 a = b = c，可以使用
a + a' = b + b' = c + c' => a - b = b' - ab, b - c = c' - b'
來確定
*/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    bool debug_mode = 1;
#else
    bool debug_mode = 0;
#endif

using ll = long long;
using ull = unsigned ll;

#define rep(i, st, ed) for (int i = (st); i < (ed); i++)
#define all(x) x.begin(), x.end()
#define cerr if(debug_mode) cerr

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n; cin >> n;
    vector<array<ll, 3>> arr(n);
    for (auto &[l, m, w] : arr) cin >> l >> m >> w;

    int mid = n / 2;

    map<array<ll, 2>, array<ll, 2>> mp;
    ll ans = -1e18;
    ll mask1 = 0, mask2 = 0;

    auto f = [&](auto self, int level, int endLevel, ll l, ll m, ll w, ll mask, bool mode) -> void {
        if (level >= endLevel) {
            if (mode == 0) {                            // front half
                array<ll, 2> id = {l - m, m - w};
                if (mp.count(id) == 0) mp[id] = {l, mask};
                else if (l > mp[id][0]) mp[id] = {l, mask};
            } else {                                    // back half
                array<ll, 2> id = {m - l, w - m};
                if (mp.count(id) == 0) return;
                
                if (mp[id][0] + l > ans) {
                    ans = mp[id][0] + l;
                    mask1 = mp[id][1];
                    mask2 = mask;
                }
            }

            return;
        }

        self(self, level + 1, endLevel, l + arr[level][0],  m + arr[level][1],  w,                  mask * 3 + 0, mode);
        self(self, level + 1, endLevel, l + arr[level][0],  m,                  w + arr[level][2],  mask * 3 + 1, mode);
        self(self, level + 1, endLevel, l,                  m + arr[level][1],  w + arr[level][2],  mask * 3 + 2, mode);
    };
    f(f, 0, mid, 0, 0, 0, 0, 0);
    f(f, mid, n, 0, 0, 0, 0, 1);

    cerr << ans << ' ' << mask1 << ' ' << mask2 << '\n';

    if (ans == -1e18) {
        cout << "Impossible";
        return 0;
    } 

    array<string , 3> maskTrans = {"LM", "LW", "MW"};
    vector<string> out1, out2;
    for (int i = 0; i < mid; i++) {
        out1.emplace_back(maskTrans[mask1 % 3]);
        mask1 /= 3;
    }
    for (int i = mid; i < n; i++) {
        out2.emplace_back(maskTrans[mask2 % 3]);
        mask2 /= 3;
    }

    reverse(all(out1)); reverse(all(out2));

    for (auto s : out1) cout << s << '\n'; for (auto s : out2) cout << s << '\n';
}