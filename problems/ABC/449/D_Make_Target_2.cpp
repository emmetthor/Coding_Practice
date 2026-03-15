// Date: 2026-03-14
/*
Tags: 幾何, 區間

解法：用 O(n) 枚舉 x 座標，再對 y 座標分段討論
可以使用排容原理，分別對塗黑的整段 (inside_all) 和在外側的黑格 (total_even - inside_even) 討論

失誤：沒有考慮空間複雜度
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
    
    int l, r, u, d; cin >> l >> r >> d >> u;

    auto count_even = [&](int _l, int _r) -> ll {
        if (_l > _r) return 0;
        // 橫跨
        if (_l <= 0 && 0 <= _r) {
            return _r / 2 + -_l / 2 + 1;
        } else {
            int transL = abs(_l), transR = abs(_r);
            if (transL > transR) swap(transL, transR);
            return transR / 2 - (transL - 1) / 2;
        }
    };

    ll ans = 0;
    ll total_even = count_even(d, u);
    for (int x = l; x <= r; x++) {
        int transX = abs(x);
        // 計算若由 x 決定的個數 [d, u] 與 [-transX, transX] 交集
        int y_low = max(-transX, d), y_hi = min(transX, u);

        ll inside_all = (y_low <= y_hi) ? (y_hi - y_low + 1) : 0;
        ll inside_even = count_even(y_low, y_hi);
        
        if (transX % 2 == 0) {
            ans += inside_all + (total_even - inside_even); // 正方形的邊長 + 同 x 的其他黑
        } else {
            ans += (total_even - inside_even); // 排除中間的其他黑
        }
    }

    cout << ans;
}