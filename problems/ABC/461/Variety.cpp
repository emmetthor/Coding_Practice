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
    
    int n, k, v; cin >> n >> k >> v;

    multiset<pair<ll, int>, greater<pair<ll, int>>> gems;
    for (int i = 0; i < n; i++)
    {
        ll value; int color; cin >> color >> value;
        gems.insert({value, color});
    }

    set<int> colors;
    vector<pair<ll, int>> rec;
    ll ans = 0;
    int cnt = 0;
    
    for (auto [value, color] : gems)
    {
        if (cnt >= k) break;
        if (cnt >= v) break;
        if (colors.insert(color).second == true)
        {
            ans += value;
            rec.push_back({value, color});
            cnt++;
            cerr << "add " << value << '\n';
        }
    }

    for (auto [value, color] : rec) gems.erase(gems.find({value, color}));

    for (auto [value, color] : gems)
    {
        if (cnt >= k) break;
        ans += value;
        rec.push_back({value, color});
        cnt++;
        cerr << "add " << value << '\n';
    }

    cout << ans;
}