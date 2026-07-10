#include <bits/stdc++.h>
using namespace std;

signed main() {
    /*第一式：區間 n 倍數計算*/
    int n, l, r;

    cout << r / n - (l - 1) / n;

    /*第二式：區間 平方數 / 立方數 / p次方數計算*/

    auto floor_sqrt = [](long long v) -> long long {
        if (v == 0)
            return 0;

        long long low = 0, hi = v;
        while (low <= hi) {
            long long mid = low + (hi - low) / 2;
            if (mid * mid > v)
                hi = mid - 1;
            else
                low = mid + 1;
            cerr << mid << '\n';
        }

        return low - 1;
    };

    cout << floor_sqrt(r) - floor_sqrt(l - 1);
}
