/*
Date: 2026-08-11

Tags:
Independent:
Understanding:
Implementation:
Recognition:

Mistakes:
*/
#include <bits/stdc++.h>
#include <math.h>
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

    struct Village
    {
        int x;
        int s;

        bool operator<(const Village &b) const
        {
            return (x == b.x ? s < b.s : x < b.x);
        }
    };

    vector<Village> villages(n); for (auto &[x, s] : villages) cin >> x >> s;

    sort(villages.begin(), villages.end());

    int low = 0, hi = 1e9;
    while (low <= hi)
    {
        int mid = (low + hi) / 2;
        cerr << ">>> trying mid = " << mid << '\n';

        int cnt = 0;
        deque<int> v, no_marks;
        vector<bool> mark(n); 
        
        int l = 0, r = 0, l2 = 0, r2 = 0;
        bool valid = 1;
        for (int center = 0; center < n; center++)
        {
            auto [cx, cs] = villages[center];
            int left = cx - mid;
            int right = cx + mid;
            while (l < n && villages[l].x < left)
            {
                if (mark[l]) cnt--;

                v.pop_front();
                if (no_marks.size() && no_marks.front() == l) no_marks.pop_front();

                l++;
            }
            while (r < n && villages[r].x <= right)
            {
                v.push_back(r);
                no_marks.push_back(r);

                r++;
            }

            //for (auto i : v) cerr << i << ' ';
            cerr << '\n';

            int need_to_mark = (cs + 1) - cnt;
            if (need_to_mark > (int)no_marks.size())
            {
                valid = 0;
                cerr << "not valid | " << need_to_mark << " > " << no_marks.size() << '\n';
                break;
            }
            else
            {
                for (int i = 0; i < need_to_mark; i++)
                {
                    mark[no_marks.back()] = 1;
                    no_marks.pop_back();
                    cnt++;
                }
                cerr << "valid, cnt = " << cnt << '\n';
            }
        }

        int all_marks = 0;
        for (int i = 0; i < n; i++) all_marks += mark[i];
        if (all_marks > k) valid = 0;

        if (valid) hi = mid - 1;
        else low = mid + 1;
    }

    cout << low;
}