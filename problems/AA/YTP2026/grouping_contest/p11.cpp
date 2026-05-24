// Date: 2026-05-24
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

    const int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
    
    int n, m; cin >> n >> m;

    auto valid = [&](int x, int y) -> bool
    {
        return x >= 0 && x < n && y >= 0 && y < m;
    };

    vector<string> mp(n); for (auto& s : mp) cin >> s;

    vector<vector<bool>> bad_square(n, vector<bool>(m));

    // mark bad squares
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
    {
        if (mp[i][j] == 'B')
        {
            queue<array<int, 2>> bfs;
            bfs.push({i, j});

            while (bfs.size())
            {
                auto [x, y] = bfs.front(); bfs.pop();

                if (bad_square[x][y]) continue;
                bad_square[x][y] = 1;

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = x + dx[dir], ny = y + dy[dir];
                    if (valid(nx, ny) && (mp[nx][ny] == 'B' || mp[nx][ny] == 'G'))
                    {
                        bfs.push({nx, ny});
                    }
                }
            }
        }
    }

    // block bad squares
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
    {
        if (bad_square[i][j])
        {
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = i + dx[dir], ny = j + dy[dir];
                if (valid(nx, ny) && mp[nx][ny] == '.')
                {
                    mp[nx][ny] = '#';
                }
            }
        }
    }
    
    // count valid G
    queue<array<int, 2>> bfs;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
    {
        cerr << mp[i][j] << " \n"[j == m - 1];
        if (mp[i][j] == 'E') bfs.push({i, j});
    }

    int ans = 0;
    vector<vector<bool>> visi(n, vector<bool>(m));
    while (bfs.size())
    {
        auto [x, y] = bfs.front(); bfs.pop();

        if (visi[x][y]) continue;
        visi[x][y] = 1;

        if (mp[x][y] == 'B')
        {
            cout << -1;
            return 0;
        }
        else if (mp[x][y] == 'G')
        {
            ans++;
        }

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir], ny = y + dy[dir];
            if (valid(nx, ny) && mp[nx][ny] != '#')
            {
                bfs.push({nx, ny});
            }
        }
    }

    cout << ans;
}