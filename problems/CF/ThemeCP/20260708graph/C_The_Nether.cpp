/*
Date: 2026-07-08

Tags: interactive, graph
Independent: 5
Understanding: 5
Implementation: 5
Recognition: 5
*/
#include <bits/stdc++.h>
#include <cassert>
#include <functional>
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
        vector<vector<int>> longest_from_node(n + 1);
        int ma = 0;
        for (int i = 1; i <= n; i++)
        {
            cout << "? " << i << ' ' << n << ' ';
            for (int i = 1; i <= n; i++)
            {
                cout << i << ' ';
            }
            cout << endl;

            int ret; cin >> ret;
            longest_from_node[ret].push_back(i);
            ma = max(ma, ret);
        }

        int curr = ma;

        vector<int> ans;
        ans.push_back(longest_from_node[curr][0]);

        curr--;
        for (; curr >= 1; curr--)
        {
            int valid_node = -1;
            for (auto i : longest_from_node[curr])
            {
                cout << "? " << ans.back() << " 2 " << ans.back() << ' ' << i << endl;

                int ret; cin >> ret;
                if (ret == 2)
                {
                    valid_node = i;
                    break;
                }
            }

            if (valid_node == -1) assert(0);

            ans.push_back(valid_node);
        }

        int sz = ans.size();
        cout << "! " << sz << ' ';
        for (int i = 0; i < sz; i++) cout << ans[i] << ' ';
        cout << endl;
    };

    while (t--) solve();
}