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

    const int MAX_N = 5000 + 5;
    
    int n; cin >> n;
    int cnt[MAX_N] = {};
    int a[MAX_N] = {};

    for (auto &i : a){
        cin >> i;
        cnt[i]++;
    }

    unordered_set<int> right;
    int tmp_cnt[MAX_N] = {};
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        unordered_set<int> in_stack;
        for (int i = 1; i <= n; i++)
        {
            if (cnt[i]) in_stack.insert(i);
        }

        right.insert(a[i]);
        if (--cnt[a[i]] == 0) in_stack.erase(a[i]);

        for (int i = 1; i <= n; i++) tmp_cnt[i] = cnt[i];

        unordered_set<int> left;
        for (int j = n - 1; i + 1 < j; j--)
        {
            left.insert(a[j]);
            if (--cnt[a[j]] == 0) in_stack.erase(a[j]);
            ans = max(ans,  int(right.size() + left.size() + in_stack.size()));
        }

        swap(cnt, tmp_cnt);
    }

    cout << ans;
}