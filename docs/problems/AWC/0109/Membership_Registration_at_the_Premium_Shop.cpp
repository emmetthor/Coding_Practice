/*
Date: 2026-07-09

Tags: priority_queue
Independent: 5
Understanding: 5
Implementation: 5
Recognition: 5
*/
#include <bits/stdc++.h>
#include <cassert>
#include <queue>
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
    
    int n, m, q; cin >> n >> m >> q;

    vector<int> priority_value(n + 1); for (int i = 1; i <= n; i++) cin >> priority_value[i];
    vector<int> capa(m + 1); for (int i = 1; i <= m; i++) cin >> capa[i];

    vector<priority_queue<int>> shops(m + 1);

    while (q--)
    {
        int p, d; cin >> p >> d;

        if (shops[d].size() < capa[d])
        {
            shops[d].push(p);
        }
        else if (shops[d].size() == capa[d])
        {
            int smallest = shops[d].top();

            if (d > smallest)
            {
                shops[d].pop();
                shops[d].push(p);
            }
            else
            {
                // rejected
            }
        }
        else assert(0);
    }    

    for (int i = 1; i <= m; i++) cout << shops[i].size() << " \n"[i == m];
}