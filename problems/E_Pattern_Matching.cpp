/*
Tag: 拓鋪排序, 二元枚舉

解法：
發現 pattern 可以推出先後順序，
因為若一個 string 可以滿足多個 pattern，則 mt 指向的 pattern 一定是最前面。

因此可用拓鋪排序。
*/
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
for qq(str, mt)

generate all 可配對的 pattern

for patterns in 可配對的 pattern:
    if index != mt
        mt -> index
    else
        mt match

if any mt 沒被配到:
    NO

topo sort

if exist cycle:
    NO
YES cout
*/

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n, m, k; cin >> n >> m >> k;

    map<string, int> hash;
    vector<string> pt(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> pt[i];
        hash[pt[i]] = i;
    }

    struct str {
        string s;
        int mt;
    };
    vector<str> strings(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> strings[i].s;
        cin >> strings[i].mt;
    }

    // 枚舉所有可能的 str -> pattern
    vector<vector<int>> e(n + 1);
    for (int i = 1; i <= m; i++) {
        auto [str, mt] = strings[i];
        bool mtSelected = 0;

        for (int j = 0; j < (1 << k); j++) {
            string key = string(k, '_');
            for (int _k = 0; _k < k; _k++) {
                if ((j >> _k) & 1) key[_k] = str[_k];
            }

            if (key == pt[mt]) {
                mtSelected = 1;
            }
            else if (hash[key] != 0) {
                e[mt].emplace_back(hash[key]);
            }
        }

        if (!mtSelected) {
            cout << "NO";
            return 0;
        }
    }

    // topu sort
    vector<bool> visi(n + 1), inStk(n + 1);
    vector<int> ans;
    bool isCycle = 0;
    auto ts = [&](auto self, int x) -> void {
        cerr << x << '\n';
        if (visi[x]) {
            if (inStk[x]) isCycle = 1;
            return;
        }

        visi[x] = 1;

        inStk[x] = 1;
        for (auto y : e[x]) self(self, y);
        inStk[x] = 0;

        ans.emplace_back(x);
    };

    for (int i = 1; i <= n; i++) {
        cerr << "go " << i << '\n';
        ts(ts, i);
    }

    if (isCycle) {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";

    reverse(all(ans));
    for (int i = 0; i < n; i++) cout << ans[i] <<" \n"[i == n - 1];
}