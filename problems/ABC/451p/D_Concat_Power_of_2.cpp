// Date: 2026-04-05
// Tags: 遞迴枚舉, 暴力
//
// 解法：
// 發現輸入 1099898 時的答案已經接近 10^9，就可以猜猜看答案其實不會太大
// 因此直接暴力找出所有 < 10^9 的所有解，再做排序就可以解決
#include <bits/stdc++.h>
#include <string>
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
    
    ll power_of_two[35];
    int cnt = 0;
    for (ll i = 1; i <= 1e9; i <<= 1) {
        power_of_two[cnt++] = i;
    }

    int power_of_two_sz[35];
    for (int i = 0; i < cnt; i++) {
        power_of_two_sz[i] = to_string(power_of_two[i]).size();
    }

    ll power_of_ten [15] = {};
    for (int i = 1; i <= 14; i++) {
        power_of_ten[i] = pow(10, i);
    }

    ll num = 0;
    int sz = 0;
    set<ll> arr;
    auto f = [&](auto self) -> void {
        if (sz > 9) return;
        else if (sz <= 9) {
            arr.insert(num);
        }

        for (int i = 0; i < cnt; i++) {
            ll tmp = num;
            num *= power_of_ten[power_of_two_sz[i]];
            num += power_of_two[i];

            sz += power_of_two_sz[i];

            self(self);

            num = tmp;
            sz -= power_of_two_sz[i];
        }
    };
    f(f);

    arr.erase(0);

    int n; cin >> n; cout << *next(arr.begin(), n - 1);

    //for (auto it = arr.begin(); it != arr.end(); it++) cerr << *it << '\n';
}