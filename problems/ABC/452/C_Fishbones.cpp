// Date: 2026-04-04
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
    
    int n; cin >> n;

    vector<pair<int, int>> ab(n);
    for (auto &[i, j] : ab) cin >> i >> j;

    int m; cin >> m;
    vector<string> ss(m);
    for (auto &s : ss) cin >> s;

    int cnt[20][20][30] = {}; // length, pos, char
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < ss[i].size(); j++) {
            //cerr << ss[i][j] << ' ';
            cnt[ss[i].size()][j + 1][ss[i][j] - 'a']++;
        }
    }

    for (int i = 0; i < m; i++) {
        if (ss[i].size() != n) {
            cout << "No\n";
            continue;
        }

        bool valid = 1;

        for (int j = 0; j < n; j++) {
            //cerr << ab[j].first << ' ' << ab[j].second << ' ' << ss[i][j] << " | " << cnt[ab[j].first][ab[j].second][ss[i][j]] << '\n';
            if (cnt[ab[j].first][ab[j].second][ss[i][j] - 'a'] < 1) valid = 0;
        }

        cout << (valid ? "Yes\n" : "No\n");
    }
}