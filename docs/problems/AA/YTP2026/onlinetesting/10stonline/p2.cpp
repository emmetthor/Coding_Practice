/*
Date: 2026-07-05

Tags:
Independent:
Understanding:
Implementation:
Recognition:

Mistakes:
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
    
    int n, m; cin >> n >> m;
    vector<vector<ll>> score(n, vector<ll>(2 * m));
    for (auto &i : score) for (auto &j : i) cin >> j;

    vector<ll> first_day_score(n);
    vector<ll> second_day_score(n);
    vector<ll> total_score(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) first_day_score[i] += score[i][j];
        for (int j = m; j < 2 * m; j++) second_day_score[i] += score[i][j];
        total_score[i] = first_day_score[i] + second_day_score[i];
    }

    vector<pair<ll, int>> sorted_total_score(n);
    for (int i = 0; i < n; i++) sorted_total_score[i] = {total_score[i], i};
    vector<ll> sorted_first_day_score = first_day_score;
    vector<ll> sorted_second_day_score = second_day_score;
    sort(sorted_total_score.begin(), sorted_total_score.end());
    sort(sorted_first_day_score.begin(), sorted_first_day_score.end());
    sort(sorted_second_day_score.begin(), sorted_second_day_score.end());

    ll au_score = sorted_total_score[n - (n / 12 + (n % 12 != 0))].first;
    ll ag_score = sorted_total_score[n - (n / 4 + (n % 4 != 0))].first;
    ll cu_score = sorted_total_score[n / 2].first;
    cerr << au_score << ' ' << ag_score << ' ' << cu_score  << '\n';

    map<ll, int> cnt;
    for (int i = 0; i < n / 2; i++)
    {
        auto [t, it] = sorted_total_score[i];
        cerr << t << ' ' << it << '\n';

        if (t == au_score || t == ag_score || t == cu_score) break;
        
        int higher1 = sorted_first_day_score.end()
                    - upper_bound(sorted_first_day_score.begin(), sorted_first_day_score.end(), first_day_score[it]);

        int higher2 = sorted_second_day_score.end()
                    - upper_bound(sorted_second_day_score.begin(), sorted_second_day_score.end(), second_day_score[it]);

        if (higher1 * 2 < n || higher2 * 2 < n)
        {
            cnt[t]++;
        }
    }

    ll mi = -1;
    int ma_cnt = 0;
    for (auto [key, v] : cnt)
    {
        cerr << key << ' ' << v << '\n';
        if (v > ma_cnt)
        {
            ma_cnt = v;
            mi = key;
        }
    }

    cout << mi;
}