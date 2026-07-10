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
    
    string s; int n; cin >> s >> n;

    for (int i = n; i < int(s.size() - n); i++) cout << s[i];
}