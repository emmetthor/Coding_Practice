/*
Date: 2026-10-17

Tags:
Independent:
Understanding:
Implementation:
Recognition:

Mistakes:
*/
#include <algorithm>
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
    vector<int> a(n); for (auto &i : a)
    {
        cin >> i;
    }
    
    int ans = 0;
    auto dfs = [&](auto self, int curr, int idx) -> void
    {
        if (idx >= n)
        {
            ans = max(ans, curr);
            return;
        }

        int res = curr + a[idx];
        string per = to_string(res);
        sort(per.begin(), per.end());

        do
        {
            int wrote = stoi(per);
            //cerr << idx << ' ' << wrote << '\n';
            self(self, wrote, idx + 1);
        } while (next_permutation(per.begin(), per.end()));

        return;
    };

    dfs(dfs, 0, 0);

    cout << ans;
}