/*
Date: 2026-07-25

Tags: equation_optimize, modulo
Independent: 5 
Understanding: 5
Implementation: 5
Recognition: 5
*/
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

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    const ll MOD = 998244353;
    using mint = Modint<MOD>;

    ll n; cin >> n;
    vector<ll> a(n + 1); for (int i = 1; i <= n; i++) cin >> a[i];
    vector<ll> prefix(n + 1); for (int i = 1; i <= n; i++) prefix[i] += prefix[i - 1] + a[i];
    auto sum = [&](int l, int r) -> ll
    {
        return prefix[r] - prefix[l - 1];
    };

    mint ans = 0;

    mint curr_sum = 0;
    
    int cnt = 1;
    for (int l = 1, r = n; l <= r; l++, r--)
    {
        curr_sum += sum(l, r);
        cerr << curr_sum.v << '\n';

        if (l == r)
        {
            cerr << "add " << curr_sum.v << " / " << cnt << '\n';
            ans += curr_sum / cnt;
        }
        else
        {
            ans += curr_sum / cnt + curr_sum / (n - cnt + 1);
            cerr << "add " << curr_sum.v << " / " << cnt << '\n';
            cerr << "add " << curr_sum.v << " / " << (n - cnt + 1) << '\n';
        }
        cnt++;
    }

    cout << ans.v;
}