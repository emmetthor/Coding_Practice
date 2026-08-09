/*
Date: 2026-08-08

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
    
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    set<int> pos;
    int ans = 0;

    while (q--)
    {
        int type; cin >> type;
        if (type == 1)
        {
            int x; cin >> x;
            if (a[x] == 0) pos.insert(x);

            ans ^= a[x];
            a[x]++;
            ans ^= a[x];

            cout << ans << '\n';
        }
        else if (type == 2)
        {
            vector<int> erase_list;
            for (auto p : pos)
            {
                ans ^= a[p];
                a[p]--;
                ans ^= a[p];

                if (a[p] == 0)
                erase_list.push_back(p);
            }
            for (auto pp : erase_list) pos.erase(pp);

            cout << ans << '\n';
        }
    }
}