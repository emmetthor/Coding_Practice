// Date: 2026-04-11
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
    Modint& operator/=(const Modint &other) {
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
    Modint inv() const {
        return pow(MOD - 2);
    }
};

using mint = Modint<998244353>;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; 
    cin >> n;

    vector<array<int, 2>> lr(n);
    for (auto &[l, r] : lr) cin >> l >> r;

    // preA[i] = 有多少人可以進大小為 i 的隊伍（也就是可進 A）
    // preB[i] = 有多少人可以進大小為 n-i 的隊伍（也就是可進 B）
    // both[i] = 有多少人對 i 而言 A/B 都可
    vector<int> preA(n + 5), preB(n + 5), both(n + 5);

    for (auto [l, r] : lr) {
        // can be in A: i in [l, r]
        preA[l]++;
        preA[r + 1]--;

        // can be in B: n - i in [l, r]
        // => i in [n-r, n-l]
        preB[n - r]++;
        preB[n - l + 1]--;

        // can be in both:
        // i in [l, r] and i in [n-r, n-l]
        int L = max(l, n - r);
        int R = min(r, n - l);
        if (L <= R) {
            both[L]++;
            both[R + 1]--;
        }
    }

    for (int i = 1; i <= n; i++) {
        preA[i] += preA[i - 1];
        preB[i] += preB[i - 1];
        both[i] += both[i - 1];
    }

    // factorial
    vector<mint> factorial(n + 1), inv_factorial(n + 1);
    factorial[0] = 1;
    for (int i = 1; i <= n; i++) {
        factorial[i] = factorial[i - 1] * i;
    }
    inv_factorial[n] = mint(1) / factorial[n];
    for (int i = n - 1; i >= 0; i--) {
        inv_factorial[i] = inv_factorial[i + 1] * (i + 1);
    }

    auto C = [&](int N, int K) -> mint {
        if (K < 0 || K > N) return 0;
        return factorial[N] * inv_factorial[K] * inv_factorial[N - K];
    };

    mint ans = 0;

    for (int i = 1; i <= n - 1; i++) {
        int k = both[i];
        int onlyA = preA[i] - k;
        int onlyB = preB[i] - k;

        // 若有人兩邊都不行，這個 i 無解
        if (onlyA + onlyB + k != n) continue;

        // A 隊大小固定為 i
        // 先塞 onlyA，剩下 i - onlyA 個從 both 裡挑
        ans += C(k, i - onlyA);
    }

    cout << ans.v << '\n';
}