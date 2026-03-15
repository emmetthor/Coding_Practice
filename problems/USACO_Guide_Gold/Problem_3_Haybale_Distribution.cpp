// Date: 2026-03-14
/*
Tags: 前綴和, 斜率二分搜

解法：發現 waste 函式可以拆成 左 與 右，並且必定是凸函數，
於是可以使用特殊的前綴和計算所有位置 左/右邊的 haybale 距離總和
就可以每個詢問 O(log MAX_POS) 解決

失誤：以為沒有 haybale 會疊在一起
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

    const int MAX_POS = 1e6 + 5;
    
    int n; cin >> n;
    
    ll pos[MAX_POS] = {};
    ll ma = 0;
    for (int i = 0; i < n; i++) {
        ll pp; cin >> pp;
        pos[pp]++;
        ma = max(pp, ma);
    }

    ll pre_suf[MAX_POS][2] = {};
    ll l_cnt = 0, r_cnt = 0;
    for (int i = 0; i < MAX_POS - 1; i++) {
        pre_suf[i + 1][0] = pre_suf[i][0] + pos[i] + l_cnt;
        if (pos[i]) l_cnt += pos[i];
    }
    for (int i = MAX_POS - 1; i >= 1; i--) {
        pre_suf[i - 1][1] = pre_suf[i][1] + pos[i] + r_cnt;
        if (pos[i]) r_cnt += pos[i];
    }

    auto f = [&](ll l, ll r, int mid) -> ll {
        return l * pre_suf[mid][0] + r * pre_suf[mid][1];
    };

    int q; cin >> q;
    while (q--) {
        ll l, r; cin >> l >> r;

        int low = 0, hi = ma;
        while (low < hi) {
            //cerr << low << ' ' << hi << '\n';
            int m = (low + hi) / 2;
            
            if (f(l, r, m) >= f(l, r, m + 1)) {
                low = m + 1;
            } else {
                hi = m;
            }
        }

        cout << f(l, r, low) << '\n';
    }
}