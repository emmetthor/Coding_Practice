// Date: 2026-04-02
// Tags: MST, Greedy
// 解法：
// 由於節點 (柵欄圍起來的空間數) 很多，因此不能用正常的 MST 結構炸開，
// 可以觀察到， Kruskal 每次找的最小權重邊，在這題的情況必定是一整個直排或橫排全選
// 因此可以記錄已經選多少直排與橫排，就可以更快的算出答案。

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

    ifstream fin("fencedin.in");
    ofstream fout("fencedin.out");

    #define cin fin
    #define cout fout
    
    int a, b, n, m; cin >> a >> b >> n >> m;
    vector<int> arr_a(n), arr_b(m);
    for (auto &i : arr_a) cin >> i; for (auto &i : arr_b) cin >> i;

    sort(arr_a.begin(), arr_a.end()); sort(arr_b.begin(), arr_b.end());

    multiset<tuple<int, int, int>> diff; // <length, vertical or horizontal, id>

    int lst = 0;
    for (int i = 0; i < n; i++) {
        diff.insert({arr_a[i] - lst, 0, i + 1});
        lst = arr_a[i];
    }
    diff.insert({a - lst, 0, n + 1});

    lst = 0;
    for (int i = 0; i < m; i++) {
        diff.insert({arr_b[i] - lst, 1, i + 1});
        lst = arr_b[i];
    }
    diff.insert({b - lst, 1, m + 1});

    int cnt_vertical = 0, cnt_horizontal = 0, used_both = 0;
    ll ans = 0;

    while (diff.size()) {
        auto [length, mode, id] = *diff.begin();
        diff.erase(diff.begin());

        if (mode == 0) {
            if (used_both == 3) {
                ans += 1ll * length * (m - cnt_horizontal + 1);
            } else {
                ans += 1ll * length * m;
            }
            cnt_vertical++;
            
            used_both |= 1;
        } else {
            if (used_both == 3) {
                ans += 1ll * length * (n - cnt_vertical + 1);
            } else {
                ans += 1ll * length * n;
            }
            cnt_horizontal++;

            used_both |= 2;
        }

        //cerr << length << ' ' << mode << ' ' << id << " | " << ans << '\n';
    }

    cout << ans;
}