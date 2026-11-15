/*
Date: 2026-11-07

Tags: observation, enumeration
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

const int MAX_V = 1e6;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n; string s; cin >> n >> s;

    vector<pair<int, int>> pos(n + 1);
    pos[0] = {0, 0};

    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, -1, 0, 1};

    int dir = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i - 1] == 'R') dir = (dir + 1) % 4;
        else if (s[i - 1] == 'L') dir = (dir + 4 - 1) % 4;

        pos[i] = {pos[i - 1].first + dx[dir], pos[i - 1].second + dy[dir]};
    }

    for (int i = 0; i <= n; i++) cerr << pos[i].first << ' ' << pos[i].second << '\n';

    vector<array<int, 4>> limit(n + 1);
    // limit[i] := 移動過程中，最大最小 x 與最大最小 y 與出發點的差向量

    array<int, 4> lst = {MAX_V, -MAX_V, MAX_V, -MAX_V};
    for (int i = n - 1; i >= 0; i--)
    {
        lst[0] = min(lst[0], pos[i + 1].first);
        lst[1] = max(lst[1], pos[i + 1].first);
        lst[2] = min(lst[2], pos[i + 1].second);
        lst[3] = max(lst[3], pos[i + 1].second);

        limit[i] = {
            lst[0] - pos[i + 1].first,
            lst[1] - pos[i + 1].first,
            lst[2] - pos[i + 1].second,
            lst[3] - pos[i + 1].second
        };
    }

    for (int i = 0; i <= n; i++) cerr << limit[i][0] << ' ' << limit[i][1] << ' ' << limit[i][2] << ' ' << limit[i][3] << '\n';

    array<int, 4> curr = {0, 0, 0, 0};
    int curr_dir = 0;

    ll ans = 1e18;
    for (int i = 0; i < n; i++)
    {
        cerr << "=== " << i << " ===\n";
        cerr << "current limit: " << curr[0] << ' ' << curr[1] << ' ' << curr[2] << ' ' << curr[3] << '\n';
        for (auto try_dir : {-1, 0, 1})
        {
            int origin_dir = (s[i] == 'S' ? 0 : (s[i] == 'L' ? -1 : 1));

            pair<int, int> npos = {
                pos[i].first + dx[(curr_dir + try_dir + 4) % 4],
                pos[i].second + dy[(curr_dir + try_dir + 4) % 4]
            };

            cerr << "origin: " << s[i] << '\n';
            cerr << "try: " << try_dir << " | " << npos.first << ' ' << npos.second << '\n';

            auto myturn = [](array<int, 4> arr, int times) -> array<int, 4>
            {
                array<int, 4> res = arr;
                times = (times + 4) % 4;
                while (times--)
                {
                    res[0] = arr[2];
                    res[1] = arr[3];
                    res[2] = -arr[1];
                    res[3] = -arr[0];

                    arr = res;
                }

                return res;
            };

            cerr << "turn: " << try_dir - origin_dir << '\n';
            auto res = myturn(limit[i], try_dir - origin_dir);
            array<int, 4> final = curr;
            final[0] = min({curr[0], npos.first, npos.first + res[0]});
            final[1] = max({curr[1], npos.first, npos.first + res[1]});
            final[2] = min({curr[2], npos.second, npos.second + res[2]});
            final[3] = max({curr[3], npos.second, npos.second + res[3]});

            cerr << "res: " << final[0] << ' ' << final[1] << ' ' << final[2] << ' ' << final[3] << '\n';
            ans = min(ans, 1ll * (abs(final[1] - final[0]) + 1) * (abs(final[3] - final[2]) + 1));
        }

        if (s[i] == 'R') curr_dir = (curr_dir + 1) % 4;
        else if (s[i] == 'L') curr_dir = (curr_dir + 4 - 1) % 4;

        curr[0] = min(curr[0], pos[i + 1].first);
        curr[1] = max(curr[1], pos[i + 1].first);
        curr[2] = min(curr[2], pos[i + 1].second);
        curr[3] = max(curr[3], pos[i + 1].second);
    }

    cout << ans;
}