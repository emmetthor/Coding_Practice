/*
Date: 2026-06-13
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

    vector<vector<int>> receive(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int k; cin >> k;
        for (int j = 0; j < k; j++)
        {
            int to; cin >> to;

            receive[to].push_back(i);
        }
    }

    for (int i = 1; i <= n; i++)
    {
            int sz = receive[i].size();
            cout << sz;
            for (int j = 0; j < sz; j++) cout << ' ' << receive[i][j];
            cout << '\n';
    }
}