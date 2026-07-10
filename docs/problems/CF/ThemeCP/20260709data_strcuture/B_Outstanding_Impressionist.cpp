/*
Date: 2026-07-09

Tags: greedy
Independent: 5
Understanding: 5
Implementation: 5
Recognition: 5
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
    
    int t; cin >> t;

    auto solve = []() -> void
    {
        int n; cin >> n;
        vector<array<int, 3>> range(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> range[i][0] >> range[i][1];
            range[i][2] = i;
        }

        sort(range.begin(), range.end());

        vector<vector<int>> cnt_of_1(2 * n + 1);
        for (auto [a, b, c] : range)
        {
            if (a == b) cnt_of_1[a].push_back(c);
        }

        set<int> in_stack;
        vector<vector<int>> starts(2 * n + 1), ends(2 * n + 1);

        for (auto [a, b, c] : range)
        {
            starts[a].push_back(c);
            ends[b].push_back(c);
        }

        vector<bool> ans(n + 1);
        for (int i = 1; i <= 2 * n; i++)
        {
            for (auto st : starts[i]) in_stack.insert(st);

            if (cnt_of_1[i].size() == 0)
            {
                // all possible
                for (auto it : in_stack)
                {
                    ans[it] = 1;
                }
                in_stack.clear();
            }
            else if (cnt_of_1[i].size() == 1)
            {
                // only the range of 1 is possible
                int it = *cnt_of_1[i].begin();
                if (in_stack.find(it) != in_stack.end())
                {
                    ans[it] = 1;
                    in_stack.erase(it);
                }
            }
            else
            {
                // no one is possible
            }

            for (auto ed : ends[i])
            {
                if (in_stack.find(ed) != in_stack.end())
                {
                    in_stack.erase(ed);
                }
            }
        }

        for (int i = 1; i <= n; i++) cout << ans[i];
        cout << '\n';
    };
 
    while (t--) solve();
}