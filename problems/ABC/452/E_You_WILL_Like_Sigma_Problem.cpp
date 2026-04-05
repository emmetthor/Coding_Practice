// Date: 2026-04-05
// Tags: 取餘, 前綴和

// 解法：
// 對於 i mod j，可以轉換成 i - j * floor(i / j)
// 因此，藉由 sigma 公式可以轉換成
// sum B_j * (i sum A_i - j * floor(i / j) * sum A_i)
// 而對於這個 floor(i / j)，會發現在固定 j 的情況下， floor(i / j) 會隨著 i 變化而會有成段的樣子，
// 也就是會 [0, 0, ..., 0], [1, 1, ..., 1], [2, ... ]
// 因此可以直接分段計算這個 floor(i / j)，i 的範圍就會是 j * floor(i / j) ~ j * (floor(i / j) + 1) - 1
// 枚舉 j，每個 j 都去計算這些段，總時間複雜度就會是 n / 1 + n / 2 + ... + n / 2 = O(n log n)

// 失誤：
// 應使用 Modint 而不是手動炸開

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    bool debug_mode = 1;
#else
    bool debug_mode = 0;
#endif

using ll = long long;
#define cerr if(debug_mode) cerr

template<int MOD>
struct Modint {
    long long v;
    Modint(long long _v = 0) {
        v = _v % MOD;
        if (v < 0) v += MOD;
    }
    Modint operator+(const Modint &other) const {
        return Modint(v + other.v);
    }
    Modint& operator+=(const Modint &other)  {
        v += other.v;
        if (v >= MOD) v -= MOD;
        return *this;
    }
    Modint operator-(const Modint &other) const {
        return Modint(v - other.v);
    }
    Modint& operator-=(const Modint &other) {
        v -= other.v;
        if (v < 0) v += MOD;
        return *this;
    }
    Modint operator*(const Modint &other) const {
        return Modint(v * other.v);
    }
    Modint& operator*=(const Modint &other) {
        v = v * other.v % MOD;
        return *this;
    }
    Modint operator/(const Modint &other) const {
        return *this * other.inv();
    }
    Modint operator/=(const Modint &other) {
        return *this *= other.inv();
    }
    Modint pow(long long times) const {
        Modint base = *this;
        Modint res = 1;
        while (times) {
            if (times & 1) res *= base;
            base *= base;
            times >>= 1;
        }
        return res;
    }
    // 模運算乘法反元素
    Modint inv() const {
        return pow(MOD - 2);
    }
};

using mint = Modint<998244353>;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n, m; cin >> n >> m;

    vector<int> a(n), b(m);
    for (auto &i : a) cin >> i;
    for (auto &j : b) cin >> j;

    vector<mint> pre_ai(n + 1), pre_iai(n + 1);
    for (int i = 1; i <= n; i++) {
        pre_ai[i] = pre_ai[i - 1] + mint(a[i - 1]);
        pre_iai[i] = pre_iai[i - 1] + mint(i) * mint(a[i - 1]);
    }

    mint ans = 0;
    for (int j = 1; j <= m; j++) {
        mint sum = 0;
        for (int k = 0; k * j <= n; k++) {
            int l = k * j;
            int r = min(n, (k + 1) * j - 1);

            mint sum1 = pre_iai[r] - pre_iai[l];
            mint sum2 = pre_ai[r] - pre_ai[l];

            sum += sum1 - mint(j) * mint(k) * sum2;
        }

        ans += mint(b[j - 1]) * sum;
    }

    cout << ans.v;
}