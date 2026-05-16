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
    
    int h, w; cin >> h >> w;

    if (h == 1 && w == 1)
    {
        cout << 0;
        return 0;
    }

    if (h == 1)
    {
        for (int i = 0; i < w; i++)
        {
            if (i == 0 || i == w - 1) cout << 1;
            else cout << 2;

            cout << " \n"[i == w - 1];
        }

        return 0;
    }

    if (w == 1)
    {
        for (int i = 0; i < h; i++)
        {
            if (i == 0 || i == h - 1) cout << 1;
            else cout << 2;

            cout << '\n';
        }

        return 0;
    }

    for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) {
        if (i == 0 || i == h - 1)
        {
            if (j == 0 || j == w - 1) cout << 2;
            else cout << 3;
        }
        else if (j == 0 || j == w - 1)
        {
            if (i == 0 || i == h - 1) cout << 2;
            else cout << 3;
        }
        else cout << 4;

        cout << " \n"[j == w - 1];
    }
}