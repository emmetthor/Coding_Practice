/*
Date: 2026-08-09

Tags:
Independent:
Understanding:
Implementation:
Recognition:

Mistakes:
*/
#include <bits/stdc++.h>
#include <istream>
#include <ostream>
using namespace std;

#ifdef LOCAL
    bool debug_mode = 1;
#else
    bool debug_mode = 0;
#endif

using ll = long long;
#define cerr if(debug_mode) cerr

const int MOD = 998244353;

template<ll m>
struct Modint
{
    ll v;
    Modint(ll _v = 0)
    {
        v = (_v % m + m) % m;
    };

    Modint operator+(const Modint& b) const
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
        return Modint(*this * b.inv());
    }
    Modint pow(ll times) const
    {
        Modint base = *this;
        Modint res = 1;
        while (times)
        {
            if (times & 1) res = res * base;
            base = base * base;
            times >>= 1;
        }
        return res;
    }
    Modint inv() const
    {
        return pow(m - 2);
    }

    friend ostream &operator<<(ostream &out, const Modint &x)
    {
        return out << x.v;
    }

    friend istream &operator>>(istream &in, const Modint &x)
    {
        ll v; in >> v;
        x = Modint(v);
        return in;
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    using mint = Modint<MOD>;

    int n, m; string s; cin >> n >> m >> s;
    s = ' ' + s;

    vector<mint> fac(n + 1);
    fac[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        fac[i] = fac[i - 1] * mint(i);
    }

    vector<vector<int>> e(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vector<vector<int>> cnt(n + 1, vector<int>(26));
    vector<bool> visi(n + 1);

    int tt = 0;
    auto dfs = [&](auto self, int x) -> void
    {
        if (visi[x]) return;
        visi[x] = 1;
        
        cnt[tt][s[x] - 'a']++;

        for (auto y : e[x]) self(self, y);
    };

    mint res = 1;
    bool can_waste_swap = 0;
    for (int i = 1; i <= n; i++)
    {
        if (visi[i]) continue;
        
        tt++;
        dfs(dfs, i);

        for (int i = 0; i < 26; i++)
        {
            cerr << cnt[tt][i] << ' ';
            if (cnt[tt][i] >= 2) can_waste_swap = 1;
        }
        cerr << '\n';
    
        int sum = 0;
        for (int i = 0; i < 26; i++)        
        {
            sum += cnt[tt][i];
            if (cnt[tt][i]) res = res / fac[cnt[tt][i]];
        }
        res = res * fac[sum];
    }

    cout << res / (can_waste_swap ? 1 : 2);
}