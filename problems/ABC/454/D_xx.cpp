// Date: 2026-04-18
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

    auto minimizer = [](string s) -> string {
        int n = s.size();

        vector<int> stk;
        vector<bool> should_remove(n);
        int diff = 0;
        bool valid = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'x') {}

            else if (s[i] == '(') {
                stk.emplace_back(i);
                diff = 0;
                valid = 1;
            }

            else if (s[i] == ')') {
                if (valid && stk.size() && i - diff - stk.back() == 3) {
                    diff += 2;
                    should_remove[stk.back()] = 1;
                    stk.pop_back();
                    should_remove[i] = 1;
                } else {
                    valid = 0;
                }
            }

            else assert(0);
        }

        string res = "";
        for (int i = 0; i < n; i++) {
            if (should_remove[i]) continue;
            
            res += s[i];
        }

        return res;
    };

    auto solve = [&]() -> void {
        string a, b; cin >> a >> b;

        int n = a.size(), m = b.size();

        string res_a = minimizer(a), res_b = minimizer(b);
        cerr << res_a << ' ' << res_b << '\n';

        cout << (res_a == res_b ? "Yes\n" : "No\n");
    };

    while (t--) solve();
}