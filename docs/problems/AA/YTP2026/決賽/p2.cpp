#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int MA=1e6+5;
int main() {
    cin.tie(0) -> sync_with_stdio(0);

    vector<bool> p(MA, 1);
    p[0] = p[1] = 0;
    for (int i = 2; i < MA; i++)
    {
        if (!p[i]) continue;
        for (int j = i + i; j < MA; j += i) p[j] = 0;
    }

    vector<ll> a;
    for (ll i = 2; i < MA; i++)
    {
        if (!p[i]) continue;
        ll it = i;
        for (int j = 2; j < 40; j++)
        {
            if (it >= 1e13 / i) break;
            it *= i;
            if (p[j + 1])
            {
                
                a.push_back(it);
                //cerr << it << '\n';
            }
        }
    }

    ll l, r; cin >> l >> r;
    sort(a.begin(), a.end());
    cout <<  upper_bound(a.begin(), a.end(), r) - lower_bound(a.begin(), a.end(), l);
}