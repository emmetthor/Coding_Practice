/*
Date: 2026-10-23

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

    const int V = 40 + 5;
    
    int m, n; cin >> m >> n;

    short a[V][V] = {};
    for (int i = 0; i <= m; i++) for (int j = 0; j <= n; j++) a[i][j] = -1;

    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) {
        char c; cin >> c;
        a[i][j] = c - 'A';
    }

    /*
    dp[i][j][k] := 當 a[i][j] 這裡有 [k](單色/雙色) 時，目前樓梯的顏色是？目前的最大樓梯是？
    
    dp[i][j][0]
    if dp[i - 1][j][0].color = dp[i][j - 1][0].color
        dp[i][j][0] = min(dp[i - 1][j][0], dp[i][j - 1][0]) + 1

    dp[i][j][1]
    if (dp[i - 1][j][1].color 兩個顏色 = dp[i][j - 1][1].color)
        pull
    else if (dp[i - 1][j][1].color 包含 dp[i][j - 1][0].color or 相反方向)
        if (pull 完的答案 = 單色的答案) dp[i][j][1] = 0
        else pull
    */
}