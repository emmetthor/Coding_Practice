#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

long long modpow(long long a, long long e) {
    long long res = 1;
    while (e > 0) {
        if (e & 1) res = res * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return res;
}

struct Comb {
    vector<long long> fact, invFact;

    Comb(int n) {
        fact.resize(n + 1);
        invFact.resize(n + 1);

        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }

        invFact[n] = modpow(fact[n], MOD - 2);
        for (int i = n - 1; i >= 0; i--) {
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;
        }
    }

    long long C(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }
};

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if (c == 0) {
        int maxN = a + b;
        Comb comb(maxN);
        cout << comb.C(a + b, a) << '\n';
        return 0;
    }

    int s = b + 1;

    int maxN = a + b + c + 5;
    Comb comb(maxN);

    long long ans = 0;

    for (int i = 1; i <= min(a, s); i++) {
        long long ways = 1;

        ways = ways * comb.C(s, i) % MOD;

        ways = ways * comb.C(a - 1, i - 1) % MOD;

        ways = ways * comb.C(b + c - i, c) % MOD;

        ans = (ans + ways) % MOD;
    }

    cout << ans << '\n';

    return 0;
}