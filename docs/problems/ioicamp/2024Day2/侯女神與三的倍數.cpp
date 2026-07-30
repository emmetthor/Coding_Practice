/*
Date: 2026-07-30

Tags: contructive, modulo
Independent: 5
Understanding: 5
Implementation: 5
Recognition: 5
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
    
    string s; cin >> s;

    int not_3k = 0;
    for (auto c : s)
    {
        int num = c - '0';
        if (num % 3 != 0) not_3k++;
    }

    if (not_3k == 1)
    {
        cout << "NO"; return 0;
    }

    auto print = [&](int pos, int num) -> void
    {
        if (pos == 0 && num > 0) cout << num;
        else if (num >= 0) cout << '+' << num;
        else cout << num;
    };

    if (not_3k % 2 == 0)
    {
        int idx = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int num = s[i] - '0';
            
            if (num % 3 == 0)
            {
                print(i, num); continue;
            }

            print(i, num * (idx % 2 == 0 ? 1 : -1) * (num % 3 == 1 ? 1 : -1));
            idx++;
        }
    }
    else
    {
        int cnt = 0;
        int idx = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int num = s[i] - '0';

            if (num % 3 == 0)
            {
                print(i, num); continue;
            }

            if (cnt < 3)
            {
                print(i, num * (num % 3 == 1 ? 1 : -1));
                cnt++;
            }
            else
            {
                print(i, num * (idx % 2 == 0 ? 1 : -1) * (num % 3 == 1 ? 1 : -1));
            }

            idx++;
        }
    }
}