/*
Date: 2026-06-13

Tags: difference
Independent: 5
Understanding: 5
Implementation: 5
Recognition: 3

Mistakes: overcomplicated_solution
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
    
    int n, d; cin >> n >> d;
    struct Sus
    {
        int start = -1, end = -1;
    };
    vector<Sus> suspect(n);

    int ma_time = 0;
    for (auto &[st, ed] : suspect)
    {
        cin >> st >> ed;
        ma_time = max(ma_time, ed);
    }

    sort(suspect.begin(), suspect.end(), [](const Sus& s1, const Sus& s2)
    {
        if (s1.start == s2.start) return s1.end > s2.end;
        else return s1.start < s2.start;
    });

    for (auto [st, ed] : suspect) cerr << st << ' ' << ed << '\n';

    multiset<int> end_times;
    ll ans = 0;
    for (int time = 0, idx = 0; time <= ma_time; time++)
    {
        int crime_end_time = time + d;
        while (idx < n && suspect[idx].start == time)
        {
            if (suspect[idx].end >= crime_end_time) 
                end_times.insert(suspect[idx].end);
            idx++;
        }

        ll sz = end_times.size();
        ans += (sz - 1) * sz / 2;
        //cerr << time << ' ' << sz << '\n';

        auto remove = end_times.find(crime_end_time);
        if (remove != end_times.end()) end_times.erase(crime_end_time);
    }

    cout << ans;
}