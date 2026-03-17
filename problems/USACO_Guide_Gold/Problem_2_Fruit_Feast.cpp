// Date: 2026-03-16
/*
Tags: 新增狀態 dp

解法：發現可以喝水一次，因此可以在 dp[i] := 可否達到 fullness i 加入 [j] := 是否喝過水，
最後加入兩次分開時間的轉移式 (因為同時，j = 1 不會被算到) 即可解題
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
    
    ifstream fin("feast.in");
    ofstream fout("feast.out");

    #define cin fin
    #define cout fout

    int t, a, b; cin >> t >> a >> b;
    
    vector<array<int, 2>> dp(t + 1);
    dp[0][0] = 1;
    for (int i = 0; i <= t; i++) {
        if (i + a <= t) {
            dp[i + a][0] |= dp[i][0];
        }
        if (i + b <= t) {
            dp[i + b][0] |= dp[i][0];
        }

        dp[i / 2][1] |= dp[i][0];
    }
    for (int i = 0; i <= t; i++) {
        if (i + a <= t) {
            dp[i + a][1] |= dp[i][1];
        }
        if (i + b <= t) {
            dp[i + b][1] |= dp[i][1];
        }
    }

    for (int i = t; i >= 0; i--) {
        if (dp[i][0] || dp[i][1]) {
            cout << i;
            return 0;
        }
    }
}