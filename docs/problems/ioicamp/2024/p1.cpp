/*
Date: 2026-10-14

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
    
    int n; cin >> n;
    vector<int> a(n); for (auto &i : a) cin >> i;

    vector<pair<int, int>> arr;

    for (auto i : a)
    {
        int longest = 0;
        int curr = 0;
        for (int j = 0; j < 31; j++)
        {
            int digit = (i >> j) & 1;
            if (digit == 0)
            {
                curr = 0;
            }
            else
            {
                curr++;
            }
            longest = max(longest, curr);
        }

        arr.push_back({longest, i});
    }

    sort(arr.begin(), arr.end());

    for (auto i : arr) cout << i.second << ' ';
}