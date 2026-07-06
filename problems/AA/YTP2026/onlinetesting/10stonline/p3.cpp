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
    
    int n, i, j, l, o, s, t, z; cin >> n >> i >> j >> l >> o >> s >> t >> z;

    int k = i + j + l + o + s + t + z;

    if (2 * k + 1 > n)
    {
        cout << "No";
        return 0;
    }

    cout << "Yes\n";

    vector<array<int, 2>> ans(n);
    int cnt = 1;
    int lst = 0;

    // o
    for (int _ = 0; _ < o; _++) 
    {
        int p = 2 * _ + lst;
        ans[p][0] = ans[p][1] = ans[p + 1][0] = ans[p + 1][1] = cnt++;
    }
    lst += 2 * o;

    // i j l;
    int ijl_cnt = min({i, j, l});
    for (int _ = 0; _ < ijl_cnt; _++)
    {
        int p = 6 * _ + lst;
        ans[p][0] = ans[p][1] = ans[p + 1][1] = ans[p + 2][1] = cnt++; //l
        ans[p + 1][0] = ans[p + 2][0] = ans[p + 3][0] = ans[p + 4][0] = cnt++; //i
        ans[p + 3][1] = ans[p + 4][1] = ans[p + 5][1] = ans[p + 5][0] = cnt++; //j
    }
    lst += 6 * ijl_cnt;
    i -= ijl_cnt; j -= ijl_cnt; l -= ijl_cnt;

    for (int _ = 0; _ < i / 2; _++)
    {
        int p = 4 * _ + lst;
        ans[p][0] = ans[p + 1][0] = ans[p + 2][0] = ans[p + 3][0] = cnt++; //i
        ans[p][1] = ans[p + 1][1] = ans[p + 2][1] = ans[p + 3][1] = cnt++; //i
    }
    lst += 2 * i;

    for (int _ = 0; _ < l / 2; _++)
    {
        int p = 4 * _ + lst;
        ans[p][0] = ans[p][1] = ans[p + 1][0] = ans[p + 2][0] = cnt++;
        ans[p + 1][1] = ans[p + 2][1] = ans[p + 3][1] = ans[p + 3][0] = cnt++;
    }
    lst += 2 * l;

    for (int _ = 0; _ < j / 2; _++)
    {
        int p = 4 * _ + lst;
        ans[p][0] = ans[p][1] = ans[p + 1][1] = ans[p + 2][1] = cnt++;
        ans[p + 1][0] = ans[p + 2][0] = ans[p + 3][1] = ans[p + 3][0] = cnt++;
    }
    lst += 2 * j;

    for (int _ = 0; _ < s; _++)
    {
        int p = 2 * _ + lst;
        ans[p][1] = ans[p + 1][1] = ans[p + 1][0] = ans[p + 2][0] = cnt++;
    }
    lst += 2 * s;

    int type = 0;
    for (int _ = 0; _ < t; _++)
    {
        int p = 2 * _ + lst;
        if (type == 0)
        {
            ans[p][1] = ans[p + 1][1] = ans[p + 1][0] = ans[p + 2][1] = cnt++;
            type ^= 1;
        }
        else
        {
            ans[p][0] = ans[p + 1][0] = ans[p + 1][1] = ans[p + 2][0] = cnt++;
            type ^= 1;
        }
    }
    lst += 2 * t;

    for (int _ = 0; _ < z; _++)
    {
        int p = 2 * _ + lst;
        ans[p][0] = ans[p + 1][0] = ans[p + 1][1] = ans[p + 2][1] = cnt++;
    }
    lst += 2 * s;

    for (int _ = 0; _ < n; _++) cout << ans[_][0] << " \n"[_ == n - 1];
    for (int _ = 0; _ < n; _++) cout << ans[_][1] << " \n"[_ == n - 1];
}