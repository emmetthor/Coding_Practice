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

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    const int V = 20;
    
    int h, w; cin >> h >> w;

    char mp[V][V]; for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) cin >> mp[i][j];

    int a1, b1, c1, d1, a2, b2, c2, d2;
    cin >> a1 >> b1 >> c1 >> d1 >> a2 >> b2 >> c2 >> d2;
    a1--; b1--; c1--; d1--; a2--; b2--; c2--; d2--;

    const int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};

    auto valid = [&](int x, int y) -> bool
    {
        return x >= 0 && x < h && y >= 0 && y < w && mp[x][y] != '#';
    };

    queue<array<int, 4>> bfs;
    bool visi[V][V][V][V] = {};
    int dis[V][V][V][V] = {};

    for (int i = 0; i < V; i++) for (int j = 0; j < V; j++) for (int k = 0; k < V; k++) for (int l = 0; l < V; l++) dis[i][j][k][l] = 1e9;

    dis[a1][b1][a2][b2] = 0;
    bfs.push({a1, b1, a2, b2});

    while (bfs.size())
    {
        auto [x1, y1, x2, y2] = bfs.front(); bfs.pop();

        if (visi[x1][y1][x2][y2]) continue;
        visi[x1][y1][x2][y2] = 1;

        cerr << "at " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << " | " << dis[x1][y1][x2][y2] << '\n';

        for (int d = 0; d < 4; d++)
        {
            auto move = [&](int x, int y, int dx, int dy) -> pair<int, int>
            {
                int nx = x + dx, ny = y + dy;
                if (nx >= h) nx = h - 1;
                if (nx < 0) nx = 0;
                if (ny >= w) ny = w - 1;
                if (ny < 0) ny = 0;
                if (mp[nx][ny] == '#')
                {
                    nx = x;
                    ny = y;
                }

                return {nx, ny};
            };

            auto [nx1, ny1] = move(x1, y1, dx[d], dy[d]);
            auto [nx2, ny2] = move(x2, y2, dx[d], dy[d]);

            dis[nx1][ny1][nx2][ny2] = min(dis[nx1][ny1][nx2][ny2], dis[x1][y1][x2][y2] + 1);

            bfs.push({nx1, ny1, nx2, ny2});
        }
    }

    if (dis[c1][d1][c2][d2] == 1e9) cout << -1;
    else cout << dis[c1][d1][c2][d2];
}