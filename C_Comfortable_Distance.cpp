/*
Tags: lower/upper_bound()

解法：對每個位置的 char 用 lower/upper_bound 求出適當的區間，再做相減
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
    
    int n, L, R; cin >> n >> L >> R;
    string s; cin >> s;

    vector<int> charPos[30] = {};
    for (int i = 0; i < n; i++) {
        charPos[s[i] - 'a'].emplace_back(i);
    }

    ll ans = 0;
    for (int i = 0; i < 26; i++) {
        auto it = charPos[i];
        int sz = it.size();
        it.emplace_back(1e9);
        for (int pt = 0; pt < sz; pt++) {
            auto r = upper_bound(all(it), it[pt] + R);
            auto l = lower_bound(all(it), it[pt] + L);

            if (l == r) continue;

            cerr << char('a' + i) << ' ' << r - l << '\n';

            ans += r - l;
        }
    }

    cout << ans;
}