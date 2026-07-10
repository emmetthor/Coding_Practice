/*
Date: 2026-07-06

Tags: counting_equivalent_states
Independent: 5
Understanding: 5
Implementation: 3
Recognition: 5

Mistakes: debugging_slow, overcomplicated_solution
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

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n; cin >> n;

    vector<string> ss(n); for (auto &s : ss) cin >> s;
    map<ll, ll> cnt;
    for (auto s : ss) cnt[stoll(s)]++;

    vector<map<ll, array<ll, 2>>> mp(6);

    for (auto s : ss)
    {
        int sz = s.size();
        for (int i = 1; i <= sz; i++)
        {
            if ((i + sz) % 2 == 1) continue; // even length

            int res = 0;
            for (int j = sz - 1; j >= sz - (i + sz) / 2; j--)
            {
                res += s[j] - '0';
            }
            for (int j = sz - (i + sz) / 2 - 1; j >= 0; j--)
            {
                res -= s[j] - '0';
            }

            mp[i][res][0]++;
            mp[i][res][1] += (i == sz);

            cerr << s << ' ' << i << ' ' << res << '\n';
        }

        for (int i = 1; i < sz; i++)
        {
            if ((i + sz) % 2 == 1) continue; // even length

            int res = 0;
            for (int j = 0; j < (i + sz) / 2; j++)
            {
                res += s[j] - '0';
            }
            for (int j = (i + sz) / 2; j < sz; j++)
            {
                res -= s[j] - '0';
            }

            mp[i][res][0]++;
            mp[i][res][1] += (i == sz);

            cerr << s << ' ' << i << ' ' << res << '\n';
        }
    }

    ll ans = 0;
    for (auto s : ss)
    {
        int sz = s.size();
        int sum = 0;
        for (auto c : s) sum += c - '0';

        ans += (mp[sz][sum][0] - mp[sz][sum][1]);
    }

    for (int i = 1; i <= 5; i++)
    {
        for (auto [key, v] : mp[i])
        {
            ans += v[1] * v[1];
        }
    }

    cout << ans;
}