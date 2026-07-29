/*
Date: 2026-07-28

Tags:
Independent:
Understanding:
Implementation:
Recognition:

Mistakes:
*/
#include <bits/stdc++.h>
#include <numeric>
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

    int ori = 0;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
    {
        cin >> a[i][j];
        ori += a[i][j];
    }
    
    vector<vector<int>> prefix(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + a[i][j];

    auto sum = [&](int x1, int y1, int x2, int y2) -> int
    {
        return prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1];
    };

    //for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cout << prefix[i][j] << " \n"[j == m];

    vector<int> horizontal_merge, vertical_merge;
    for (int i = 1; i < n; i++) vertical_merge.push_back(sum(i, 1, i + 1, m));
    for (int j = 1; j < m; j++) horizontal_merge.push_back(sum(1, j, n, j + 1));
    sort(horizontal_merge.begin(), horizontal_merge.end());
    sort(vertical_merge.begin(), vertical_merge.end());

    // for (auto i : horizontal_merge) cerr << i << ' '; cerr << '\n';
    // for (auto i : vertical_merge) cerr << i << ' '; cerr << '\n';

    int current_slice = n * m;
    vector<int> ans(current_slice + 1, -1);

    ori *= 5;
    ans[current_slice] = ori;

    for (int i = 0; i < n - 1; i++)
    {
        int tmp = current_slice;
        int tmp_ori = ori;
        for (int j = 0; j < m - 1; j++)
        {
            tmp -= n - i;
            cerr << i << ' ' << j + 1 << ' ' << tmp << '\n';
            tmp_ori -= horizontal_merge[j];
            ans[tmp] = max(ans[tmp], tmp_ori);
        }

        current_slice -= m;
        ori -= vertical_merge[i];
        ans[current_slice] = max(ans[current_slice], ori);
    }

    int tmp = current_slice;
    int tmp_ori = ori;
    for (int j = 0; j < m - 1; j++)
    {
        tmp -= 1;
        tmp_ori -= horizontal_merge[j];
        ans[tmp] = max(ans[tmp], tmp_ori);
    }

    for (int i = 1; i <= n * m; i++) cout << ans[i] << " \n"[i == n * m];

    // vector<int> a(m); for (auto &i : a) cin >> i;

    // vector<int> merge_cost;
    // for (int i = 0; i < m - 1; i++) merge_cost.push_back(a[i] + a[i + 1]);

    // sort(merge_cost.begin(), merge_cost.end());

    // vector<int> ans(m + 1);

    // int ori = 5 * accumulate(a.begin(), a.end(), 0ll);
    // ans[m] = ori;
    // for (int i = m - 1; i >= 1; i--)
    // {
    //     ori -= merge_cost[m - i - 1];
    //     ans[i] = ori;
    // }

    // for (int i = 1; i <= m; i++)
    // {
    //     cout << ans[i] << " \n"[i == m];
    // }
}