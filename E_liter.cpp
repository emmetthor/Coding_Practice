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

    T sum_range(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n, q; cin >> n >> q;
    vector<BIT<int>> bit(2);
    vector<int> lastRow(n + 1, -1), lastCol(n + 1, -1);

    ll ans = 0;
    int index = 1;
    while (q--)
    {
        int type, x; cin >> type >> x;

        if (type == 1) // black
        {
            if (lastRow[x] == -1)
            {
                ans += n;
                continue;
            }

            ans += bit[0].sum_range(lastRow[x] + 1, index - 1);

            bit[1].upd(x, -1);
        }
        else if (type == 2) // white
        {

        }
        else assert(0);

        cout << ans << '\n';
    }
}