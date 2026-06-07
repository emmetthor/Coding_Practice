// Date: 2026-06-06
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
    vector<int> a(n), b(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;

    bool valid = 1;
    for (int i = 0; i < n; i++)
    {
        if (b[a[i] - 1] - 1 != i)
        {
            valid = 0;
            break;
        }
    }

    cout << (valid ? "Yes" : "No");
}