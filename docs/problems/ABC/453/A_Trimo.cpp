// Date: 2026-04-11
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
    
    int n; string s; cin >> n >> s;
    bool valid = 1;
    for (int i = 0; i < n; i++) {
        if (!valid) cout << s[i];
        else if (s[i] != 'o') {
            cout << s[i];
            valid = 0;
        }
    }
}