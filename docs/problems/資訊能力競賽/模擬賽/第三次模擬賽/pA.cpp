/*
Date: 2026-10-17

Tags:
Independent:
Understanding:
Implementation:
Recognition:

Mistakes:
*/
#include <bits/stdc++.h>
#include <unordered_map>
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

    vector<vector<int>> e(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vector<int> color(n + 1, -1);
    auto dfs = [&](auto self, int x)
    {
        if (color[x] != -1) return;

        unordered_map<int, int> nearby;
        for (auto y : e[x])
        {
            nearby[color[y]] = 1;
        }

        int mycolor = 1;
        while (nearby[mycolor] == 1) mycolor++;

        color[x] = mycolor;
        for (auto y : e[x])
        {
            self(self, y);
        }
    };

    for (int i = 1; i <= n; i++) dfs(dfs, i);

    cout << *max_element(color.begin(), color.end()) << '\n';
    for (int i = 1; i <= n; i++) cout << color[i] << " \n"[i == n];
}