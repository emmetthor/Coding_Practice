// Date: 2026-03-20
#include <bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
    bool debug_mode = 1;
#else
    bool debug_mode = 0;
#endif
 
using ll = long long;
using ull = unsigned ll;
 
#define rep(i, st, ed) for (int i = (st); i < (ed); i++)
#define all(x) x.begin(), x.end()
#define cerr if(debug_mode) cerr
 
/*
dp[i][j] := 到 (i, j) 是否是最佳的字元
*/
 
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n; cin >> n;
 
    vector<string> mp(n);
    for (auto &s : mp) cin >> s;
 
    vector<vector<bool>> bestPath(n, vector<bool>(n + 1));
    bestPath[0][0] = 1;
 
    string res = "";
    res += mp[0][0];
 
    for (int step = 0; step < 2 * n - 1 - 1; step++) {
        char best = 'z';
        for (int r = 0; r <= min(n - 1, step); r++) {
            int c = step - r;
 
            if (c >= n || bestPath[r][c] != 1) continue;
 
            if (c + 1 < n) best = min(best, mp[r][c + 1]);
            if (r + 1 < n) best = min(best, mp[r + 1][c]);
        }
 
        res += best;
        for (int r = 0; r <= min(n - 1, step); r++) {
            int c = step - r;
 
            if (c >= n || bestPath[r][c] != 1) continue;
 
            if (c + 1 < n && mp[r][c + 1] == best) bestPath[r][c + 1] = 1;
            if (r + 1 < n && mp[r + 1][c] == best) bestPath[r + 1][c] = 1;
        }
    }
 
    cout << res;
}
