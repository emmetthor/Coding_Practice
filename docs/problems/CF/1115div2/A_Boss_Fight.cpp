/*
Date: 2026-08-06

Tags: associative_containers
Independent: 5
Understanding: 5
Implementation: 5
Recognition: 5

Mistakes: wrong_proof
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
    
    const int MAX_A = 1000 + 5;

    int t; cin >> t;

    auto solve = []()
    {
        int n; cin >> n;
        int cnt[MAX_A] = {};
        for (int i = 0; i < n; i++)
        {
            int ai; cin >> ai;
            cnt[ai]++;
        }

        set<pair<int, int>> cards;
        for (int i = 0; i < MAX_A; i++)
        {
            if (cnt[i] == 0) continue;
            cards.insert({cnt[i], i});
        }

        int ans = 0;
        int lst = 0;
        while (cards.size() >= 2)
        {
            auto [bkc, bkv] = *prev(cards.end());
            auto [pbkc, pbkv] = *prev(cards.end(), 2);

            cards.erase(prev(cards.end()));
            cards.erase(prev(cards.end()));

            ans += bkv + pbkv;
            if (bkc > 1) cards.insert({bkc - 1, bkv});
            if (pbkc > 1) cards.insert({pbkc - 1, pbkv});

            lst = pbkv;
        }

        if (cards.size() == 1)
        {
            auto [c, v] = *cards.begin();
            if (lst == v) ans += v;
            else ans += v * min(c, 2);
        }

        cout << ans << '\n';
    };

    while (t--) solve();
}