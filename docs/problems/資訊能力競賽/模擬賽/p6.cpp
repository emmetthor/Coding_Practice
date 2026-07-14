/*
Date: 2026-07-12

Tags: dp, matrix
Independent: 4
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

struct Matrix {
    int n, m;
    vector<vector<ll>> mat;
    int MOD = 1e9 + 7;

    // 加法單位元素
    Matrix (int _n, int _m, bool multiply = 0) : mat(_n, vector<ll>(_m, 0)) {
        n = _n; m = _m;

        if (multiply) {
            assert(n == m);
            *this = identity(n);
        }
    }

    // 乘法單位元素
    Matrix identity (int sz) {
        Matrix res(sz, sz);
        for (int i = 0; i < sz; i++) res.mat[i][i] = 1;
        return res;
    }

    Matrix operator*(const Matrix &b) const {
        assert(m == b.n);

        Matrix res(n, b.m);
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
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cout << this->mat[i][j] << " \n"[j == m - 1];
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    const int MOD = 1e9 + 7;
    
    ll t; cin >> t;

    Matrix ori(1, 6);
    ori.mat[0][0] = 1;
    Matrix trans(6, 6);
    trans.mat = {
        {0, 1, 0, 1, 0, 0},
        {1, 0, 1, 0, 1, 0},
        {0, 1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 0},
        {0, 1, 0, 1, 0, 1},
        {0, 0, 1, 0, 1, 0}
    };

    auto res = ori * trans.pow(t);
    //res.print();
    int ans = 0;

    for (int i = 0; i < 6; i++) ans = (ans + res.mat[0][i]) % MOD;

    cout << ans;
}