// Date: 2026-06-06
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    bool debug_mode = 1;
#else
    bool debug_mode = 0;
#endif

using ll = long long;
#define cerr if(debug_mode) cerr

template<typename T>
class BIT {
private:
    int n;
    vector<T> b;
 
public:
    BIT(int _n) : n(_n), b(_n + 1, 0) {};
 
    // 更新位於 x 的值 (加上 v)
    void upd(int x, T v) {
        for (; x <= n; x += x & -x) {
            b[x] += v;
        }
    }
 
    // 計算 1 ~ x 的前綴和
    T sum(int x) {
        T res = 0;
        for (; x; x -= x & -x) {
            res += b[x];
        }
        return res;
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n, q; cin >> n >> q;
    BIT<int> black(n + 1), white(n + 1);
}