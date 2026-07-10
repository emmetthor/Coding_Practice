// Date: 2026-04-05
// Tags: BIT, 前綴和
// 解法：要求出恰好 k 個逆序數對的連續子區間，可以以前綴和的角度看成：
// 至少 k 個 - 至少 k - 1 個 的答案
// 這樣就可以用雙指標求出答案
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    bool debug_mode = 1;
#else
    bool debug_mode = 0;
#endif

using ll = long long;
#define cerr if(debug_mode) cerr

template<typename T>
class BIT {
private:
    int n;
    vector<T> b;

public:
    BIT(int _n) : n(_n), b(_n + 1, 0) {};

    // 更新位於 x 的值 (加上 v)
    void upd(int x, T v) {
        for (; x <= n; x += x & -x) {
            b[x] += v;
        }
    }

    // 計算 1 ~ x 的前綴和
    T sum(int x) {
        T res = 0;
        for (; x; x -= x & -x) {
            res += b[x];
        }
        return res;
    }

    // 求第 k 小
    T kth(T k) {
        int h = __lg(n) + 1;
        int curr = 0;

        for (int i = h; i >= 0; i--) {
            if (curr + (1 << i) <= n && b[curr + (1 << i)] < k) {
                k -= b[curr + (1 << i)];
                curr += (1 << i);
            }
        }

        return curr + 1;
    }
};


int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n; cin >> n;
    ll k; cin >> k;
    
    vector<int> a(n); for (auto &i : a) cin >> i;

    auto f = [&](ll cnt) -> ll {
        BIT<int> bit(n + 1);

        ll res = 0, curr = 0;
        for (int l = 0, r = 0; l < n; l++) {
            // bit.sum(n) - bit.sum(a[r]): 加入 r 之後新增的逆序數對個數
            while (r < n && curr + bit.sum(n) - bit.sum(a[r]) <= cnt) {
                curr += bit.sum(n) - bit.sum(a[r]);
                bit.upd(a[r], 1);
                r++;
            }

            cerr << l << ' ' << r << '\n';
            res += r - l;

            // 移動左界，更新
            curr -= bit.sum(a[l] - 1) - bit.sum(0);
            bit.upd(a[l], -1);
        }

        return res;
    };

    cout << f(k) - (k == 0 ? 0 : f(k - 1));
}