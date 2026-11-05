/*
Date: 2026-10-11
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
    
    int n, q; cin >> n >> q;
    vector<ll> L(n + 1, 1e18), R(n + 1, 1e18);
    for (int i = 2; i <= n; i++) cin >> L[i];
    for (int i = 1; i <= n - 1; i++) cin >> R[i];

    vector<ll> minL(n + 1);
    minL[n] = L[n];
    for (int i = n - 1; i >= 1; i--)
    {
        minL[i] = min(minL[i + 1], L[i]);
    }
    vector<ll> minR(n + 1);
    minR[1] = R[1];
    for (int i = 2; i <= n; i++)
    {
        minR[i] = min(minR[i - 1], R[i]);
    }

    while (q--)
    {
        int s, t; cin >> s >> t;
        if (s < t)
        {
            cout << min(R[s], L[s] + minR[s]) << '\n';
        }
        else if (s > t)
        {
            cout << min(L[s], R[s] + minL[s]) << '\n';
        }
    }
}