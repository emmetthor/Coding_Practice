// Date: 2026-05-23
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
    
    int n; cin >> n;

    set<int> s;

    int cnt_0 = 0;
    for (int i = 0; i < n; i++)
    {
        int ai; cin >> ai;
        if (ai == 0)
        {
            cnt_0++;
            continue;
        }

        if (s.insert(ai).second == false)
        {
            cout << "NO";
            return 0;
        }
    }

    if (cnt_0 > 26)
        cout << "NO";
    else
        cout << "YES";
}