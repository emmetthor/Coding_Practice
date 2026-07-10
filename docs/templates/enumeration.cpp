#include <bits/stdc++.h>
using namespace std;

signed main() {
    /*第一式：全排列枚舉*/
    vector<int> a;
    sort(a.begin(), a.end());

    do {
        /*執行操作*/
    } while (next_permutation(a.begin(), a.end()));

    /*第二式：二元枚舉*/
    int n;
    vector<int> a;
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1 == 1) {
                /*執行操作*/
            }
        }
    }
    /*第三式：折半枚舉*/
    /*O(3) O(4) 優化*/
    int required_sum;
    map<int, int> v;
    for (int k = 2; k < n; k++) {
        for (int i = 0; i < k - 1; i++) {
            v[a[i] + a[k - 1]]++; /*先計算前兩個相加*/
        }
        for (int i = k + 1; i < n; i++) {
            /* 枚舉後兩個相加，是否有前兩個相加可以滿足條件*/
            if (v.find(required_sum - a[i] - a[k]) != v.end()) {
                cout << "YES\n";
                return 0;
            }
        }
    }

    /*O(2^n) 優化*/
    int m;
    map<int, int> cnt;
    for(int i = 0; i < (1 << n); i++) {
        int s = 0;
        for(int j = 0; j < n; j++) {
            if((i >> j) & 1) {
                /*執行操作*/
            }
        }
    }
    for(int i = 0; i < (m << n); i++) {
        int s = 0;
        for(int j = 0; j < n; j++) {
            if((i >> j) & 1) {
                /*執行操作 記得索引加上 n*/
            }
        }
    }
}
