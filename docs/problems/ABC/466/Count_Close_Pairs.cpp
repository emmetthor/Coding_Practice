/*
Date: 2026-07-11

Tags: interactive, same_side_two_pointer
Independent: 5
Understanding: 5
Implementation: 5
Recognition: 5

Mistakes: debugging_slow
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
    
    int n; cin >> n;

    int ans = 0;
    for (int i = 1, j = 2; i < n; i++)
    {
        j = max(i + 1, j);
        string res;
        while (j <= n)
        {
            cout << "? " << i << ' ' << j << endl;
            cin >> res;

            if (res == "Yes")
            {
                j++;
            }
            else
            {
                break;
            }
        }

        int cnt = j - i;
        ans += cnt - 1;
    }

    cout << "! " << ans << endl;
}