/*
Date: 2026-10-24

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

void solve() {
    int n, k;
    cin >> n >> k;

    vector<vector<bool>> dir(n, vector<bool>(n));

    auto dfs = [&](auto self, int x, int y) -> int
    {
        if (x + y == n - 1) return y;

        if (dir[x][y] == 0)
        {
            dir[x][y] = 1;
            return self(self, x + 1, y);
        }
        else
        {
            dir[x][y] = 0;
            return self(self, x, y + 1);
        }
    };

    vector<int> ans((1 << (n - 1)) + 1);
    for (int i = 1; i <= (1 << (n - 1)); i++)
    {
        ans[i % (1 << (n - 1))] = dfs(dfs, 0, 0);
    }

    cout << ans[k % (1 << (n - 1))] << '\n';

    return;
}

int main()
{
    cin.tie(0) -> sync_with_stdio(0);

    int t; cin >> t;
    while (t--) solve();
}