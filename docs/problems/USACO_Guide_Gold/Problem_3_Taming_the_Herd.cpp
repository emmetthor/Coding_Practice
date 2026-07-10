// Date: 2026-04-15
// Tags: 分段DP
//
// 解法：
// 發現答案可以由 [ 前面一段答案 ] + [ 後面從 k 開始到結尾改成 0, 1, 2 ... n - k 的答案 ]，
// 因此暫定狀態 [ 處理到第 i 項 ]
// 又因為題目需要知道總共用幾次 [0, 1, 2, ...][0, 1, 2, ...]... [0, 1, 2...]，因此可以設計 dp 為
// dp[i][j] := 處理到第 i 項時已經有 j 段，這時的最小答案
// 又發現計算每段 cost 其實可以暴力 O(n^3) 算，因此就可以解題了
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
    
    ifstream fin("taming.in");
    ofstream fout("taming.out");

    #define cin fin
    #define cout fout

    const int MAX_V = 105;
    const int INF = 100;

    int n; cin >> n;
    int a[MAX_V];
    for (int i = 1; i <= n; i++) cin >> a[i];

    int cost[MAX_V][MAX_V] = {};
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            for (int k = i; k <= j; k++) {
                cost[i][j] += (a[k] == k - i ? 0 : 1);
            }
        }
    }

    int dp[MAX_V][MAX_V] = {};
    for (int i = 0; i < MAX_V; i++) for (int j = 0; j < MAX_V; j++) dp[i][j] = INF;
    for (int i = 1; i <= n; i++) dp[i][1] = cost[1][i];

    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= i; j++) {
            for (int k = 2; k <= i; k++) {
                dp[i][j] = min(dp[i][j], dp[k - 1][j - 1] + cost[k][i]);
            }
        }
    }

    for (int i = 1; i <= n; i++) cout << dp[n][i] << '\n';
}