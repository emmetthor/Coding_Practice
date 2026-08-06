/*
Date: 2026-08-05

Tags: rolling_hash
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

struct HashString
{
    int n;
    string s;
    ll m;
    ll b;
    vector<ll> pow;
    vector<ll> hash_table;

    HashString(string _s, ll _m = 1e9 + 7, ll _b = 114514)
    : n(_s.size()), s(_s), m(_m), b(_b), hash_table(_s.size() + 1)
    {
        int pp = 1;
        for (int i = 0; i <= n; i++)
        {
            pow.push_back(pp);
            pp = pp * b % m;
        }

        for (int i = 0; i < n; i++)
        {
            hash_table[i + 1] = (hash_table[i] * b % m + (s[i] - 'a' + 1)) % m;
        }
    }

    ll get(int l, int r)
    {
        return ((hash_table[r + 1] - hash_table[l] * pow[r - l + 1] % m) % m + m) % m;
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    string s; cin >> s;
    int n = s.size();
    HashString hsh(s);

    for (int len = 1; len <= n; len++)
    {
       if (hsh.get(0, n - len - 1) == hsh.get(len, n - 1)) cout << len << ' '; 
    }
}