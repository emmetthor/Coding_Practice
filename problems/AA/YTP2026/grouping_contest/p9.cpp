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
    
    int t; cin >> t;

    auto solve = []() -> void
    {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (auto &i : a) cin >> i;
        for (auto &i : b) cin >> i;

        int m; cin >> m;
        unordered_map<int, int> tool;
        for (int i = 0; i < m; i++) {
            int ai; cin >> ai;
            tool[ai]++;
        }

        // NO
        bool valid = 1;
        for (int i = 0; i < n; i++)
        {
            if (a[i] < b[i])
            {
                valid = 0;
            }
        }

        if (!valid)
        {
            cout << "NO\n";
            return;
        }

        // OK

        vector<int> stk;
        unordered_map<int, int> need;

        b.push_back(1e9);

        for (int i = 0; i <= n; i++)
        {
            while (stk.size() && stk.back() < b[i])
            {
                need[stk.back()]++;
                stk.pop_back();
            }

            if (i < n && a[i] > b[i])
            {
                if (stk.empty() || stk.back() > b[i])
                {
                    stk.push_back(b[i]);
                }
            }
        }

        for (auto [x, cnt] : need)
        {
            if (tool[x] < cnt)
            {
                valid = 0;
            }
        }

        cout << (valid ? "YES" : "NO") << '\n';
    };

    while (t--) solve();
}