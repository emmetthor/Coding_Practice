/*
Date: 2026-08-06

Tags: rolling_hash
Independent: 3
Understanding: 5
Implementation: 5
Recognition: 5
*/
#include <bits/stdc++.h>
#include <fstream>
using namespace std;

#ifdef LOCAL
    bool debug_mode = 1;
#else
    bool debug_mode = 0;
#endif

using ll = long long;
#define cerr if(debug_mode) cerr

const ll hm = 1e9 + 7;
const ll hb = 114514;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    ifstream cif("censor.in");
    ofstream cof("censor.out");
    
    string s, t; cif >> s >> t;
    int n = s.size(), m = t.size();

    auto next_hash = [&](ll bk, char c) -> ll
    {
        return (bk * hb % hm + (c - 'a' + 1)) % hm;
    };

    ll hash_t = 0;
    for (int i = 0; i < m; i++) hash_t = next_hash(hash_t, t[i]); 

    string ans;
    vector<ll> hash_prefix = {0};
    vector<ll> pow = {1};
    for (int i = 0; i < n; i++)
    {
        ans += s[i];
        hash_prefix.push_back(next_hash(hash_prefix.back(), s[i]));
        pow.push_back(pow.back() * hb % hm);

        if (ans.size() >= m)
        {
            ll raw = hash_prefix.back() - hash_prefix[ans.size() - m] * pow[m] % hm;
            ll match_hsh = (raw + hm) % hm;

            if (hash_t == match_hsh)
            {
                cerr << ans.substr(ans.size() - m, m);
                ans.resize(ans.size() - m);
                hash_prefix.resize(hash_prefix.size() - m);
            }
        }
    }

    cof << ans;
}