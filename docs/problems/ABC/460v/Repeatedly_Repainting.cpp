// Date: 2026-05-31
/*
Tags: 2d_map_implementation, bfs
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

    const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1},
              dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    
    int h, w; cin >> h >> w;

    auto valid = [&](int x, int y) -> bool
    {
        return x >= 0 && x < h && y >= 0 && y < w;
    };

    vector<string> mp(h); for (auto &s : mp) cin >> s;
    vector<vector<bool>> first_black(h, vector<bool>(w));

    // do a oper
    for (int i = 0; i < h; i++) for (int j = 0; j < w; j++)
    {
        if (mp[i][j] == '#')
        {
            for (int dir = 0; dir < 8; dir++)
            {
                int nx = i + dx[dir], ny = j + dy[dir];

                if (valid(nx, ny))
                {
                    first_black[nx][ny] = 1;
                }
            }
        }
    }

    vector<vector<int>> res(h, vector<int>(w));
    vector<vector<bool>> visi(h, vector<bool>(w));

    queue<array<int, 2>> bfs;
    for (int i = 0; i < h; i++) for (int j = 0; j < w; j++)
    {
        if (mp[i][j] == '.' && first_black[i][j])
        {
            bfs.push({i, j});
            visi[i][j] = 1;
            cerr << '*';
        }
        else cerr << '.';
        cerr << " \n"[j == w - 1];
    }

    while (bfs.size())
    {
        auto [x, y] = bfs.front(); bfs.pop();

        for (int dir = 0; dir < 8; dir++) {
            int nx = x + dx[dir], ny = y + dy[dir];

            if (valid(nx, ny) && !visi[nx][ny])
            {
                res[nx][ny] = res[x][y] + 1;
                visi[nx][ny] = 1;
                bfs.push({nx, ny});
            }
        }
    }

    for (int i = 0; i < h; i++) for (int j = 0; j < w; j++)
    {
        cerr << res[i][j] << " \n"[j == w - 1];
        if (res[i][j] % 2 == 1) cout << '#';
        else cout << '.';

        if (j == w - 1) cout << '\n';
    }
}