/*
Date: 2026-07-05

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
    
    int n, m; cin >> n >> m;

    if (n % 2 == 1 && m % 2 == 1)
    {
        cout << "NO";
        return 0;
    }

    if (n == 1)
    {
        if (m != 2) cout << "NO";
        else cout << "YES\n1 1";
        return 0;
    }
    if (m == 1)
    {
        if (n != 2) cout << "NO";
        else cout << "YES\n1\n1";
        return 0;
    }

    bool swapped = false;
    if (m % 2 == 1)
    {
        swap(n, m);
        swapped = true;
    }

    vector<vector<int>> ans(n, vector<int>(m));

    int cnt = 1;
    int new_n = n;

    if (n % 2 == 1)
    {
        int type = 0;
        for (int j = 0; j < m; j += 2)
        {
            if (type == 0)
            {
                ans[n - 3][j] = ans[n - 3][j + 1] = cnt++;
                ans[n - 2][j] = ans[n - 1][j] = cnt++;
                ans[n - 2][j + 1] = ans[n - 1][j + 1] = cnt++;
                type ^= 1;
            }
            else
            {
                ans[n - 3][j] = ans[n - 2][j] = cnt++;
                ans[n - 3][j + 1] = ans[n - 2][j + 1] = cnt++;
                ans[n - 1][j] = ans[n - 1][j + 1] = cnt++;
                type ^= 1;
            }
        }

        new_n -= 3;
    }

    cerr << "fill 2x2\n";

    int type = 0;
    for (int i = new_n - 1; i >= 0; i -= 2)
    {
        int cnt_change = 0;
        for (int j = 0; j < m; j += 2)
        {
            if (type == 0)
            {
                ans[i][j] = ans[i - 1][j] = cnt++;
                ans[i][j + 1] = ans[i - 1][j + 1] = cnt++;
                type ^= 1;
            }
            else
            {
                ans[i][j] = ans[i][j + 1] = cnt++;
                ans[i - 1][j] = ans[i - 1][j + 1] = cnt++;
                type ^= 1;
            }
            cnt_change++;
        }

        if (cnt_change % 2 == 0) type ^= 1;
    }

    cout << "YES\n";

    if (swapped) swap(n, m);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
    {
        if (swapped) cout << ans[j][i] << " \n"[j == m - 1];
        else cout << ans[i][j] << " \n"[j == m - 1];
    }
}