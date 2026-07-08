/*
Date: 2026-07-08

Tags: dfs, graph
Independent: 5
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

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n, t; cin >> n >> t;

    vector<vector<int>> e(n + 1);

    for (int i = 1; i < n; i++)
    {
        int a; cin >> a;
        e[i].push_back(i + a);
    }

    vector<bool> visi(n + 1);
    auto dfs = [&](auto self, int x) -> void
    {
        if (visi[x]) return;
        visi[x] = 1;

        for (auto y : e[x]) self(self, y);
    };

    dfs(dfs, 1);

    cout << (visi[t] ? "YES" : "NO");
}