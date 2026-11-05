/*
Date: 2026-10-14

Tags:
Independent:
Understanding:
Implementation:
Recognition:

Mistakes:
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
    
    int n, m; cin >> m >> n;

    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) for (int j = m; j >= 1; j--) cin >> a[i][j];

    vector<array<int, 3>> ans;

    auto operation = [&](int id1, int layer, int id2) -> void
    {
        if (layer <= 0) return;
        ans.push_back({id1, layer, id2});
    };

    auto myswap = [&](int x1, int y1, int x2, int y2) -> void
    {
        if (y1 < y2)
        {
            swap(y1, y2);
            swap(x1, x2);
        } 

        int tmp = n + 1;
        operation(x1, y1, tmp);
        operation(x2, y2, x1);
        operation(tmp, y1 - y2, x1);
        operation(tmp, y2, x2);
        operation(x2, y2 - 1, tmp);
        operation(x1, y1 - y2, tmp);
        operation(x1, y2 - 1, x2);
        operation(tmp, y1 - 1, x1);
    };

    for (int i = 1; i <= n; i++)
    {
        int iter = 1;
        for (int j = i + 1; j <= n; j++)
        {
            for (int k = 1; k <= m; k++)
            {
                if (a[j][k] == i)
                {
                    while (iter <= m && a[i][iter] == i) iter++;
                    cerr << "swap (" << i << ',' << iter << ") <-> (" << j << ',' << k << ")\n";
                    cerr << a[i][iter] << '\n';
                    myswap(i, iter, j, k);
                    swap(a[i][iter], a[j][k]);
                    iter++;
                }
            }
        }
    }

    cout << ans.size() << '\n';
    for (auto [s, k, t] : ans) cout << s << ' ' << k << ' ' << t << '\n';

}