// Date: 2026-05-23
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

    vector<string> mp(n + 5, string(n + 5, '.'));
    for (int i = 1; i <= n; i++)
    {
        cin >> mp[i];
        mp[i] = ' ' + mp[i];
    }


    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
    {
        if (mp[i][j] != '#') continue;

        if ((mp[i - 1][j - 1] == '#' && mp[i - 1][j + 1] == '#') ||
            (mp[i - 1][j + 1] == '#' && mp[i + 1][j + 1] == '#') ||
            (mp[i + 1][j + 1] == '#' && mp[i + 1][j - 1] == '#') ||
            (mp[i + 1][j - 1] == '#' && mp[i - 1][j - 1] == '#'))
        {
            cout << i << ' ' << j << '\n';
            return 0;
        }
    }

    if (mp[1][1] == '#') cout << "1 1" << '\n';
    else if (mp[1][n] == '#') cout << "1 " << n << '\n';
}