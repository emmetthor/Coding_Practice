/*
Date: 2026-07-24
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
    
    int low = 1, hi = 1024;

    while (low <= hi)
    {
        int mid = (low + hi) / 2;
        cout << mid << endl;
        char res; cin >> res;

        if (res == '>') low = mid + 1;
        else if (res == '<') hi = mid - 1;
        else return 0;
    }

    cout << low << endl;
}