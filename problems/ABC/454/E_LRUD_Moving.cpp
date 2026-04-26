// Date: 2026-04-18
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
    
    int t; cin >> t;

    auto solve = [&]() {
        int n, a, b; cin >> n >> a >> b;
        a--; b--;

        if (n & 1 || ((a + b) & 1) == 0) { cout << "No\n"; return; }

        string pre = "", suf = "";

        // 處理 兩層橫排
        for (int i = 0; i < n / 2 - 1; i++) {
            string path = string(n - 1, 'R') + 'D' + string(n - 1, 'L') + 'D';
            if (a >= 2) {
                a -= 2;
                pre += path;
            } else {
                suf += path;
            }
        }

        // 處理 2 * n 的直排
        for (int i = 0; i < n / 2 - 1; i++) {
            string path_front = "DRUR", path_back = "RURD";
            if (b >= 2) {
                pre += path_front;
                b -= 2;
            } else {
                suf += path_front;
            }
        }

        // 處理 2 * 2 含 # 的方框
        if (a == 0 && b == 1) {
            pre += "DR";
        } else {
            pre += "RD";
        }

        reverse(suf.begin(), suf.end());

        cout << "Yes\n" << pre + suf << '\n';
    };

    while (t--) solve();
}