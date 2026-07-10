/*
Date: 2026-07-09

Tags: stack
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

    stack<char> stk;

    for (int i = 0; i < s.size(); i++)
    {
        if (stk.size() && stk.top() == s[i])
        {
            stk.pop();
        }
        else
        {
            stk.push(s[i]);
        }
    }

    cout << stk.size();
}