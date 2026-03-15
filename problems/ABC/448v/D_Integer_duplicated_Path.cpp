// Date: 2026-03-15
/*
Tags: 等價類計數, 簡易樹論

解法：由於樹上的 path 是固定的，因此可以直接 DFS 並回滾紀錄所有出現數的次數
注意若只看最新加入的數，會讓已經有重複 interger 的點被忽視，因此若父節點可行，其子樹皆可以
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
    
    int n; cin >> n;
    vector<int> value(n + 1); for (int i = 1; i <= n; i++) cin >> value[i];

    vector<vector<int>> e(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }

    map<int, int> cnt;
    vector<bool> valid_path(n + 1);

    auto dfs = [&](auto self, int x, int lst) -> void {
        cnt[value[x]]++;
        if (cnt[value[x]] >= 2) valid_path[x] = 1;
        if (valid_path[lst]) valid_path[x] = 1;

        for (auto y : e[x]) {
            if (y == lst) continue;
            self(self, y, x);
        }

        cnt[value[x]]--;
    }; dfs(dfs, 1, 1);

    for (int i = 1; i <= n; i++) cout << (valid_path[i] == 1 ? "Yes\n" : "No\n");
}