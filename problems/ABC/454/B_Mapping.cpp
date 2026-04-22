// Date: 2026-04-18
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
    
    int n, m; cin >> n >> m;

    vector<int> cnt(m + 1);
    for (int i = 0; i < n; i++) {
        int ai; cin >> ai;
        cnt[ai]++;
    }

    bool onlyOne = 1;
    bool everyType = 1;
    for (int i = 1; i <= m; i++) {
        if (cnt[i] > 1) onlyOne = 0;
        if (cnt[i] == 0) everyType = 0;
    }

    cout << (onlyOne ? "Yes" : "No") << '\n' << (everyType ? "Yes" : "No");
}