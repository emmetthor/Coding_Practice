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
    int lst = -1;
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        int ai; cin >> ai;

        if (ai >= lst) ans.emplace_back(ai);
        else
        {
            ans.emplace_back(1);
            ans.emplace_back(ai);
        }

        lst = ai;
    }

    int sz = ans.size();
    cout << sz << '\n';
    for (int i = 0; i < sz; i++) cout << ans[i] << " \n"[i == sz - 1];
}