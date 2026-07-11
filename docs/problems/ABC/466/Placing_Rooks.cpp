/*
Date: 2026-07-11

Tags: associative_containers
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
    
    int n, m; cin >> n >> m;

    vector<set<int>> row(n + 1), col(n + 1);

    while (m--)
    {
        int r, c; cin >> r >> c;

        vector<array<int, 2>> remove_pos;

        for (auto i : row[r]) remove_pos.push_back({r, i});
        row[r].clear();

        for (auto i : col[c]) remove_pos.push_back({i, c});
        col[c].clear();

        for (auto [_r, _c] : remove_pos)
        {
            if (row[_r].find(_c) != row[_r].end()) row[_r].erase(_c);
            if (col[_c].find(_r) != col[_c].end()) col[_c].erase(_r);
        }

        row[r].insert(c);
        col[c].insert(r);
    }

    set<array<int, 2>> res;

    for (int i = 1; i <= n; i++)
    {
        for (auto c : row[i]) res.insert({i, c});
        for (auto r : col[i]) res.insert({r, i});
    }

    cout << res.size();
}