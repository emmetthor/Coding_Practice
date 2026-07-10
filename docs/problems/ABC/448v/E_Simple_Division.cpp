// Date: 2026-03-15
/*
Tags: 模運算, 矩陣快速冪

解法：發現 M 與 10007 特別小，而又要做 floor 這種無法以模運算達成的操作，於是可以把模數直接設為 M * 10007，
就可以留下對 floor 必要的資訊直接除法

失誤：太晚發現 M 其實很小
*/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    bool debug_mode = 1;
#else
    bool debug_mode = 0;
#endif

using ll = unsigned long long;
#define cerr if(debug_mode) cerr

struct Modint {
    long long v;
    long long MOD;
    Modint(long long _v = 0, int mod = 1e9 + 7) {
        MOD = mod;
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

const ll INF = 1e18;

struct Matrix {
    int n, m;
    vector<vector<ll>> mat;
    ll MOD = 1e9 + 7;

    // 加法單位元素
    Matrix (int _n, int _m, ll mod) : mat(_n, vector<ll>(_m, 0)) {
        n = _n; m = _m;

        MOD = mod;
    }

    // 乘法單位元素
    Matrix identity (int sz) {
        Matrix res(sz, sz, MOD);
        for (int i = 0; i < sz; i++) res.mat[i][i] = 1;
        return res;
    }

    Matrix operator*(const Matrix &b) const {
        assert(m == b.n);

        Matrix res(n, b.m, MOD);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < b.m; j++) {
                for (int k = 0; k < m; k++) {
                    res.mat[i][j] += mat[i][k] * b.mat[k][j];
                    if (res.mat[i][j] >= MOD) res.mat[i][j] %= MOD;
                }
            }
        }

        return res;
    }

    // 方陣快速冪
    Matrix pow(ll t) {
        assert(n == m);

        Matrix res = identity(n);
        Matrix base = *this;

        while (t) {
            if (t & 1) res = res * base;
            base = base * base;
            t >>= 1;
        }

        return res;
    }

    void print() {
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cerr << this->mat[i][j] << " \n"[j == m - 1];
    }
};


int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int k, m; cin >> k >> m;
    ll mod_number = m * 10007;

    Matrix ori(1, 2, mod_number);
    ori.mat = {{0, 1}};
    
    for (int i = 0; i < k; i++) {
        ll c, l; cin >> c >> l;

        Matrix trans(2, 2, mod_number);
        trans.mat = {
            {10, 0},
            {c, 1}
        };

        //trans.pow(1).print();

        ori = ori * trans.pow(l);
    }

    cerr << ori.mat[0][0] << '\n';

    ll res = ori.mat[0][0];
    res /= m;

    cout << res % 10007;
}