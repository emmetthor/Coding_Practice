/*
Date: 2026-07-27

Tags: constructive, tree
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
    
    // cin
    int m; cin >> m;
    vector<int> cnt(m); for (auto &i : cnt) cin >> i;
    vector<vector<int>> a(m);
    for (int i = 0; i < m; i++) for (int j = 0; j < cnt[i]; j++)
    {
        int ai; cin >> ai;
        a[i].push_back(ai);
    }

    // check valid n;
    int total_cnt = accumulate(cnt.begin(), cnt.end(), 0);
    int n = 0;
    for (; n <= 10000; n++)
    {
        if (total_cnt == n * (n + 1) / 2) break;
    }

    if (n == 10001)
    {
        cout << -1;
        return 0;
    }

    // cut sausage into two lines
    array<vector<int>, 2> line;
    int line_cnt = 0;

    for (int i = 0; i < m; i++)
    {
        if (i % 2 == 0)
        {
            // even -> --
            for (int j = cnt[i] - 1; j >= 0; j--)
            {
                line[line_cnt].push_back(a[i][j]);
            }
        }
        else
        {
            // odd -> ++
            for (int j = 0; j < cnt[i]; j++)
            {
                line[line_cnt].push_back(a[i][j]);
            }
            line_cnt++;
        }
    }

    vector<vector<int>> ans(n + 1);
    int iter1 = 0, iter2 = 0;
    for (int i = n; i >= 1; i--)
    {
        int line1_len = line[0].size() - iter1, line2_len = line[1].size() - iter2;
        if (line1_len >= i)
        {
            for (int t = 0; t < i; t++)
                ans[i].push_back(line[0][iter1 + t]);
            iter1 += i;
        }
        else if (line2_len >= i)
        {
            for (int t = 0; t < i; t++)
                ans[i].push_back(line[1][iter2 + t]);
            iter2 += i;
        }
    }

    cout << n << '\n';
    for (int i = 1; i <= n; i++) for (int j = 0; j < i; j++) cout << ans[i][j] << " \n"[j == i - 1];
}