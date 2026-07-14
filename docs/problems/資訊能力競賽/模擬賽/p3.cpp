/*
Date: 2026-07-12
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
    
    const int MAX_V = 1e6;
    const int MOD = 1e9 + 7;

    vector<bool> p(MAX_V, 1);
    p[0] = p[1] = 0;

    for (int i = 2; i * i < MAX_V; i++)
    {
        if (p[i] == 1)
        {
            for (int j = i * i; j < MAX_V; j += i) {
                p[j] = 0;
            }
        }
    }

    vector<int> p_list;
    for (int i = 0; i < MAX_V; i++)
    {
        if (p[i]) 
        {
            p_list.push_back(i);
            //cerr << i << ' ';
        }
    }
    //cerr << '\n';

    int p_sz = p_list.size();
    vector<int> can_use(p_sz);
    int valid_pair = 0;

    for (int i = 0, j = p_sz - 1; i < p_sz; i++)
    {
        int pp = p_list[i];
        can_use[i]++;
        if (1ll * pp * pp * pp <= MAX_V) can_use[i]++;

        while (j >= 0 && 1ll * pp * p_list[j] > MAX_V) j--;
        can_use[i] += j + 1;
        valid_pair += max(0, j - i + 1);
    }
    cerr << valid_pair << '\n';

    can_use.push_back(1); // 1 可以用 1

    for (int i = 0; i < p_sz; i++) 
    {
        //cerr << p_list[i] << ' ' << can_use[i] << '\n';
        can_use[i] %= MOD;
    }

    int n, m; cin >> n >> m;

    vector<int> g(n);
    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        if (g[i] == 0)
        {
            for (int j = i; j < n; j += m)
            {
                g[j] = cnt;
            }
            cnt++;
        }
    }

    vector<int> cnt_list(cnt);
    for (int i = 0; i < n; i++) cnt_list[g[i]]++;
    
    auto fast_pow = [&](int a, int b) -> int
    {
        int res = 1;
        while (b > 0) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }

        return res;
    };

    int ans = 0;
    for (int i = 0; i < cnt; i++)
    {
        if (cnt_list[i] != 0)
        {
            //cerr << cnt_list[i] << '\n';
            for (int j = 0; j <= p_sz; j++)
            {
                ans += fast_pow(can_use[j], cnt_list[i]);
            }
        }
    }

    cout << ans - valid_pair;
}