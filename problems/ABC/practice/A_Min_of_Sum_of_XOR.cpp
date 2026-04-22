// Date: 2026-04-14
// Tags: XOR, 構造
//
// 解法：
// 1. 看到 XOR 就先把每個數依照 bit 拆開來看
// 2. 會發現有一些成本根本無法省略，例如在 XOR 過程中必定會在某一位數出現 1 一下，又被 XOR 掉
// 3. 因此可以想想看：有沒有辦法讓每個 bit 的 1 都只出現一下子就會不見。
// 4. 會發現若把 bit 1 與下一數的 bit 1 排在一起，就可以最快把 bit 1 移除。
// 5. 將 1 ~ 7 的數字依 bit 寫出來，會發現若把 1 2 3 4 排成 1 3 2 4，如下：
//
// 1 - 0 0 1
// 3 - 0 1 1
// 2 - 0 1 0
// 4 - 1 0 0
//
// 每次 XOR 時都可以恰好把相鄰的 bit XOR 掉，而 4 的最高位 bit 也會在 5 ~ n 時快速消去，因此這就是構造解的方式
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

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        vector<int> p(N);
        iota(p.begin(), p.end(), 1);

        // swap positions 2 and 3, 6 and 7, 10 and 11, ...
        // 0-indexed: swap (1,2), (5,6), (9,10), ...
        for (int i = 1; i + 1 < N; i += 4) {
            swap(p[i], p[i + 1]);
        }

        for (int i = 0; i < N; i++) {
            if (i) cout << ' ';
            cout << p[i];
        }
        cout << '\n';
    }
    return 0;
}