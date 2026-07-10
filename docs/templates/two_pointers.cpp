#include <bits/stdc++.h>
using namespace std;

signed main() {
    /*第一型：遞迴 (分治)*/
    auto f = [&](auto self, int l, int r) -> int {
        if (l > r)
            return 0;
        if (l == r)
            return 1; /*回傳需要的值*/

        int m = (l + r) / 2;
        int ret1 = self(self, l, m);
        int ret2 = self(self, m + 1, r);

        return ret1 + ret2; /*回傳需要的值*/
    };

    /*第二型：單調數列*/
    /*雙正向*/
    int n;
    for (int i = 0, j = 0; i < n; i = j) {
        while (j < n && 1 /*判斷式*/)
            j++;
    }

    /*一正一反*/
    for (int i = n - 1, j = 0; i >= 0; i--) {
        while (j < n && 1 /*判斷式*/)
            j++;
    }

    /*第三型：滑動窗口*/
    for (int l = 0, r = 0; r < n; r++) {
        /*計算右界往前的貢獻*/

        /*計算左界往前的貢獻*/
        while (r < n && 1 /*判斷式*/)
            l++;

        /*計算這次區間往前的貢獻*/
    }
}
