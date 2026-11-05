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

void solve()
{
    int n, k; cin >> n >> k;

    vector<vector<int>> state(n, vector<int>(n));
    state[0][0] = k - 1;

    for (int sum = 0; sum <= n - 2; sum++)
    {
        for (int x = 0; x <= sum; x++)
        {
            int y = sum - x;
            
            int right = state[x][y] / 2;
            state[x + 1][y] += state[x][y] - right;
            state[x][y + 1] += right;
        }
    }

    auto dfs2 = [&](auto self, int x, int y) -> int
    {
        if (x + y == n - 1) return y;
        if ((state[x][y]) % 2 == 0)
        {
            return self(self, x + 1, y);
        }
        else
        {
            return self(self, x, y + 1);
        }
    };

    cout << dfs2(dfs2, 0, 0) << '\n';
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int t; cin >> t;
    while (t--) solve();
}