/*
Date: 2026-08-10

Tags:
Independent:
Understanding:
Implementation:
Recognition:

Mistakes:
*/
#include <bits/stdc++.h>
#include <ostream>
using namespace std;

#ifdef LOCAL
    bool debug_mode = 1;
#else
    bool debug_mode = 0;
#endif

using ll = long long;
#define cerr if(debug_mode) cerr

template<ll m>
struct Modint
{
    ll v;
    Modint(ll _v = 0)
    {
        v = (_v % m + m) % m;
    };

    Modint operator+(const Modint &b) const
    {
        return Modint(v + b.v);
    }
    Modint operator-(const Modint &b) const
    {
        return Modint(v - b.v);
    }
    Modint operator*(const Modint &b) const
    {
        return Modint(v * b.v);
    }
    Modint operator/(const Modint &b) const
    {
        return *this * b.inv();
    }
    Modint inv() const
    {
        return this -> pow(m - 2);
    }
    Modint pow(ll times) const
    {
        Modint res = 1, base = v;
        while (times)
        {
            if (times & 1) res = res * base;
            base = base * base;
            times >>= 1;
        }
        return res;
    }
    friend ostream &operator<<(ostream &out, const Modint x)
    {
        out << x.v;
        return out;
    }
};

using mint = Modint<998244353>;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    const int MAX_N = 1e6 + 5;
    
    mint fac[MAX_N] = {};
    fac[0] = 1;
    fac[1] = 1;
    for (int i = 2; i < MAX_N; i++)
    {
        fac[i] = fac[i - 1] * i;
    }

    auto C = [&](int n, int k) -> mint
    {
        if (n < 0 || k < 0) return 1;
        return fac[n] / (fac[k] * fac[n - k]);
    };

    int t; cin >> t;

    auto solve = [&]()
    {
        int n; string s; cin >> n >> s;
        int cnt[2] = {};
        int block[2] = {};

        for (int i = 0, j = 0; i < n; i = j)
        {
            while (j < n && s[i] == s[j]) j++;
            cnt[s[i] - '0'] += j - i;
            block[s[i] - '0']++;
        }

        cerr << cnt[0] << ' ' << cnt[1] << ' ' << block[0] << ' ' << block[1] << '\n';
        cerr << C(cnt[0] - 1, block[0] - 1) << ' ' << C(cnt[1] - 1, block[1] - 1) << '\n';
        cout << C(cnt[0] - 1, block[0] - 1) * C(cnt[1] - 1, block[1] - 1) << '\n';
    };

    while (t--) solve();
}