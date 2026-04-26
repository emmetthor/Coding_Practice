// Date: 2026-04-25
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
    
    int n, q; cin >> n >> q;

    vector<int> parent(n + 1), child(n + 1);
    for (int i = 1; i <= n; i++) parent[i] = -i, child[i] = -1;

    while (q--) {
        int c, p; cin >> c >> p;

        if (parent[c] > 0) child[parent[c]] = -1;
        parent[c] = p;
        child[p] = c;
    }

    vector<int> ans(n + 1);

    for (int i = 1; i <= n; i++) {
        cerr << "#" << i << '\n';
        if (parent[i] < 0) {
            int cnt = 1;
            int it = i;
            while (child[it] > 0) {
                cerr << it << ' ';
                cnt++;
                it = child[it];
            }

            ans[-parent[i]] = cnt;
            cerr << '\n';
        }
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
}