#include <bits/stdc++.h>
#include <iomanip>
#include <set>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n, k; cin >> n >> k;

    multiset<int> a; for (int i = 0; i < n; i++)
    {
        int ai; cin >> ai;
        a.insert(ai);
    }

    map<ll, int> ans;
    map<pair<int, multiset<int>>, bool> visi;
    ll cnt = 0;

    auto dfs = [&](auto self, int round, multiset<int> arr) -> vector<ll>
    {
        if (visi[{round, arr}])
        {
            for ()
        }
        if (round == k + 1)
        {
            ll res = 1;
            for (auto i : arr) res *= i;
            ans[res]++;
            cnt++;
            //cout << "add " << res << '\n';
            return vector{res};
        }

        int x = (round % 2 == 1 ? *prev(arr.end()) : *arr.begin());
        arr.erase(arr.find(x));

        vector<ll> res;

        for (int i = 0; i <= x; i++)
        {
            arr.insert(i);
            auto it = self(self, round + 1, arr);
            for (auto i : it) res.push_back(i);
            arr.erase(arr.find(i));
        }

        return res;
    };

    dfs(dfs, 1, a); 

    double final_ans = 0;
    for (auto [key, value] : ans)
    {
        //cout << key << ' ' << value << '\n';
        final_ans += double(value) / double(cnt) * double(key);
    }

    cout << fixed << setprecision(20) << final_ans;
}