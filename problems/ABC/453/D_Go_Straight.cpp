// Date: 2026-04-11
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
    
    int h, w; cin >> h >> w;

    vector<string> mp(h); for (auto &s : mp) cin >> s;

    int moveStk[5000005] = {};
    int back_iterator = 0;
    vector<vector<array<bool, 5>>> visi(h, vector<array<bool, 5>>(w));

    const int dx[] = {0, 0, -1, 1};
    const int dy[] = {-1, 1, 0, 0};
    const string trans = "LRUD";

    auto valid = [&](int x, int y) -> bool {
        return x >= 0 && x < h && y >= 0 && y < w && mp[x][y] != '#';
    };

    auto dfs = [&](auto self, int x, int y, int dir) -> void {
        if (!valid(x, y)) return;
        if (visi[x][y][dir]) return;

        if (mp[x][y] == 'G') {
            cout << "Yes\n";
            for (int i = 0; i < back_iterator; i++) cout << trans[moveStk[i]];
            exit(0);
        }

        //cout << x << ' ' << y << '\n';

        visi[x][y][dir] = 1;

        for (int d = 0; d < 4; d++) {
            if (mp[x][y] == 'o' && d != dir) continue;
            if (mp[x][y] == 'x' && d == dir) continue;

            moveStk[back_iterator++] = d;
            self(self, x + dx[d], y + dy[d], d);
            back_iterator--;
        }
    };

    for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) {
        if (mp[i][j] == 'S') dfs(dfs, i, j, 4);
    }

    cout << "No";
}