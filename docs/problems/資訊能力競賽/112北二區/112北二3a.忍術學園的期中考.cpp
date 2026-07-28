/*
Date: 2026-07-27

Tags: greedy, permutation, state_compression
Independent: 5
Understanding: 5
Implementation: 5
Recognition: 5
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
    
    int h, w; cin >> h >> w;

    auto id = [&](int x, int y) -> int
    {
        return w * x + y;
    };

    auto print = [&](int mp) -> void
    {
        for (int i = 0; i < h; i++) for (int j = 0; j < w; j++)
        {
            cerr << ((mp >> id(i, j)) & 1u) << " \n"[j == w - 1];
        }
    };

    int mp = 0;
    for (int i = 0; i < h; i++) for (int j = 0; j < w; j++)
    {
        int a; cin >> a;
        if (a) mp += (1u << id(i, j));
    }

    if (mp == 0)
    {
        cout << 0;
        return 0;
    }

    //print(mp);

    vector<int> use_mask;
    for (int i = 0; i < h - 2; i++) for (int j = 0; j < w - 2; j++)
    {
        int res = 0;
        for (int dx = 0; dx < 3; dx++) for (int dy = 0; dy < 3; dy++)
        {
            cerr << i + dx << ' ' << j + dy << '\n';
            res += (1u << id(i + dx, j + dy));
        }
        use_mask.push_back(res);
        // print(res);
        // cerr << '\n';
    }

    int sz = (h - 2) * (w - 2);
    vector<int> permutation;
    for (int i = 0; i < sz; i++) permutation.push_back(i);

    int ans = 1e9;
    do
    {
        int nmp = mp;

        for (int t = 0; t < sz; t++)
        {
            int mask = use_mask[permutation[t]];
            nmp ^= mask;
            if (nmp == 0) ans = min(ans, t + 1);
        }
    } while (next_permutation(permutation.begin(), permutation.end()));

    cout << (ans == 1e9 ? -1 : ans);
} 