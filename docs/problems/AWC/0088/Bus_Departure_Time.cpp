/*
Date: 2026-06-10
*/
#include <algorithm>
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
    
    int n, k; cin >> n >> k;
    vector<int> a(n); for (auto &i : a) cin >> i;
    cout << *max_element(a.begin(), a.end()) + k;
}