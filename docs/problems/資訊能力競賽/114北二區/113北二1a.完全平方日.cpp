/*
Date: 2026-07-23

Tags: math
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
    
    int n; cin >> n;

    if (n == 0)
    {
        cout << "20241001";
        return 0;
    }

    int month_days[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    auto check = [&](ll date) -> bool
    {
        string s = to_string(date);

        int len = s.size();
        int day = stoi(s.substr(len - 2, 2));
        int month = stoi(s.substr(len - 4, 2));
        int year = stoi(s.substr(0, len - 4));

        cerr << year << ' ' << month << ' ' << day << '\n';

        if (1 <= month && month <= 12 && 1 <= day && day <= month_days[month]) return 1;
        else return 0;
    };
    
    if (n > 0)
    {
        int cnt = 0;
        ll num = 4500;

        while (cnt < n)
        {
            if (check(num * num)) cnt++;
            num++;
        }

        cout << (num - 1) * (num - 1);
    }
    else
    {
        int cnt = 0;
        ll num = 4498;

        while (cnt < -n)
        {
            if (check(num * num)) cnt++;
            num--;
        }

        cout << (num + 1) * (num + 1);
    }
}