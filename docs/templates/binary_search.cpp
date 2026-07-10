#include <bits/stdc++.h>
using namespace std;

signed main() {
    /*第一式：一般式*/
    /*整數*/
    int low = 0; /*最小值*/
    int hi = 100; /*最大值*/
    while (low <= hi) {
        int mid = low + (hi - low) / 2; /*有負數必須用此式*/
        if (mid /*判斷式*/)
            low = mid + 1;
        else
            hi = mid - 1;
    }

    /*小數*/
    double low = 0; /*最小值*/
    double hi = 100; /*最大值*/
    for(int i = 0; i < 300; i++) { /*重複 300 次，必可以找到*/
        double mid = low + (hi - low) / 2; /*有負數必須用此式*/
        if (mid /*判斷式*/)
            low = mid;
        else
            hi = mid;
    }

    cout << low; /*low 和 hi 的差別在於要尋找的位置不同*/

    /*第二式：第 k 小*/
    /*把要求出第 k 小的數，改成求出此數 x 使比 x 小的數至少有 k 個，即可使用二分搜0*/

    /*第三式：01二分搜*/
    /*平均值極值*/
    int n;
    int d;
    vector<int> a(n + 1);
    auto f = [&](int mid) -> bool {
        vector<int> b = a;
        for (auto &i : b)
            i -= mid; /*將所有數減去 mid，代表任意數的平均已經有 mid*/

        vector<int> pre(n + 1);
        partial_sum(a.begin(), a.end(), pre.begin());

        int mi = 1e9;
        for (int i = d; i <= n; i++) {
            int j = i - d;
            if (pre[j] >= 0) /*最小的前綴*/
                mi = pre[i];
            if (pre[i] >= mi) /*只要有一個區間的總和 > 0，就代表他的平均至少有 mid*/
                return 1;
        }
        return 0;
    };

    int low = 0; /*最小值*/
    int hi = 100; /*最大值*/
    while (low <= hi) {
        int mid = low + (hi - low) / 2; /*有負數必須用此式*/
        if (f(mid))
            low = mid + 1;
        else
            hi = mid - 1;
    }

    cout << low;

    /*第四式：三分搜*/
    /*對斜率二分搜*/
    int low = 0; /*最小值*/
    int hi = 100; /*最大值*/
    while (low <= hi) {
        int m1 = low + (hi - low) / 3;
        int m2 = m1 + 1;
        if (1 /*判斷式*/)
            low = m1 + 1;
        else
            hi = m2 - 1;
    }

    /*平分三段*/
    int low = 0; /*最小值*/
    int hi = 100; /*最大值*/
    while (low <= hi) {
        int m1 = low + (hi - low) / 3;
        int m2 = hi - m1;
        if (1 /*判斷式*/)
            low = m1 + 1;
        else
            hi = m2 - 1;
    }
}
