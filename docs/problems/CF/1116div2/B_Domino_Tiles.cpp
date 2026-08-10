/*
Date: 2026-08-09

Tags: observation
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
    
    auto solve = []()
    {
        int n; string s; cin >> n >> s;
        
        int ans = 0;
        for (auto c1 : {'0', '1'})
        {
            for (auto c2 : {'0', '1'})
            {
                string curr = "";
                curr += c1;
                curr += c2;

                for (int i = 2; i < n; i++)
                {
                    int lst_sum = curr[i - 1] - '0' + curr[i - 2] - '0';
                    for (auto c3 : {'0', '1'})
                    {
                        if (c3 - '0' + curr[i - 1] - '0' == lst_sum) continue;
                        curr += c3;
                    }
                }

                bool valid = 1;
                for (int i = 0; i < n; i++)
                {
                    if (s[i] != '?' && curr[i] != s[i])
                    {
                        valid = 0;
                        break;
                    }   
                }
                if (valid) ans++;
            }
        }

        cout << ans << '\n';
    };

    while (t--) solve();
}