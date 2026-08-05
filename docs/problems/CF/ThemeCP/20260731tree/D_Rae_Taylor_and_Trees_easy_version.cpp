/*
Date: 2026-07-31

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
    
    int t; cin >> t;

    auto solve = []()
    {
        int n; cin >> n;
        set<int> in_stack;
        
        int lst_max = n + 1;
        bool valid = 1;
        for (int i = 0; i < n; i++)
        {
            int ai; cin >> ai;

            if (i > 0)
            {
                if (ai < lst_max && in_stack.empty()) valid = 0;
            }
            for (int j = ai + 1; j < lst_max; j++) in_stack.insert(j); 
            if (in_stack.find(ai) != in_stack.end()) in_stack.erase(ai);

            lst_max = min(lst_max, ai);
        }

        cout << (valid ? "Yes\n" : "No\n");
    };

    while (t--) solve();
}