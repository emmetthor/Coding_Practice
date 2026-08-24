/*
Date: 2026-08-22

Tags: muiti_source, bfs
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

    const int dx[] = {0, 0, -1, 1};
    const int dy[] = {-1, 1, 0, 0};
    
    int h, w, k; cin >> h >> w >> k;

    vector<string> mp(h); for (auto &s : mp) cin >> s;

    vector<bool> empty_row(h), empty_col(w);

    for (int i = 0; i < h; i++)
    {
        bool valid = 1;
        for (int j = 0; j < w; j++)
        {
            if (mp[i][j] == '#') valid = 0;
        }
        empty_row[i] = valid;
    }

    for (int j = 0; j < w; j++)
    {
        bool valid = 1;
        for (int i = 0; i < h; i++)
        {
            if (mp[i][j] == '#') valid = 0;
        }
        empty_col[j] = valid;
    }

    queue<array<int, 3>> bfs;
    for (int i = 0; i < h; i++) for (int j = 0; j < w; j++)
    {
        if (empty_row[i] && empty_col[j])
        {
            bfs.push({i, j, 0});
            cerr << "safe: " << i << ' ' << j << '\n';
        }
    }

    vector<vector<bool>> visi(h, vector<bool>(w));

    auto check = [&](int x, int y) -> bool
    {
        return x >= 0 && x < h && y >= 0 && y < w && mp[x][y] != '#';
    };

    while (bfs.size())
    {
        auto [x, y, step] = bfs.front(); bfs.pop();

        if (visi[x][y]) continue;
        visi[x][y] = 1;

        if (step >= k) continue;

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir], ny = y + dy[dir];
            if (check(nx, ny))
            {
                bfs.push({nx, ny, step + 1});
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) ans += visi[i][j] == 1;

    cout << ans;
}