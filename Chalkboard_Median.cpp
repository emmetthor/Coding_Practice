// Date: 2026-05-16
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
    
    int x, q; cin >> x >> q;

    multiset<int> ft, ed;
    ed.insert(x);
    auto it = ed.begin();

    while (q--)
    {
        int a, b; cin >> a >> b;

        if (a > b) swap(a, b);

        if (*ed.begin() <= a)
        {
            ft.insert(*ed.begin());
            ed.erase(ed.begin());
            ed.insert(a);
            ed.insert(b);
        }

        else if (a <= *ed.begin() && *ed.begin() <= b)
        {
            ft.insert(a);
            ed.insert(b);
        }

        else if (b <= *ed.begin())
        {
            if (ft.size())
            {
                ft.insert(a);
                ft.insert(b);
                ed.insert(*ft.rbegin());
                ft.erase(prev(ft.end()));
            }
            else
            {
                ft.insert(a);
                ed.insert(b);
            }
        }
        else assert(0);

        assert(*prev(ft.end()) <= *ed.begin());

        cout << *ed.begin() << '\n';
    }
}