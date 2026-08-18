/*
Date: 2026-08-17

Tags:
Independent:
Understanding:
Implementation:
Recognition:

Mistakes:
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
    
    int n, m; cin >> n >> m;
    vector<vector<ll>> c(n, vector<ll>(m)), v(n, vector<ll>(m)), k(n, vector<ll>(m));

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> c[i][j];
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> v[i][j];
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> k[i][j];

    vector<vector<pair<ll, ll>>> limit(m);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            limit[i].push_back({v[j][i], k[j][i]});
        }
        
        sort(limit[i].begin(), limit[i].end(), greater<>());
    }

    ll ans = 0;
    for (int i = 0; i < m; i++)
    {
        ll cnt = 0;
        for (int j = 0; j < n; j++)
        {
            cnt += c[j][i];
        }

        cerr << "type " << i << " has " << cnt << '\n';

        int it = 0;
        while (cnt > 0)
        {
            auto [value, local_limit] = limit[i][it++];
            
            if (cnt >= local_limit)
            {
                ans += value * local_limit;
                cnt -= local_limit;
            }
            else
            {
                ans += value * cnt;
                cnt = 0;
            }
        }
    }

    cout << ans;
}