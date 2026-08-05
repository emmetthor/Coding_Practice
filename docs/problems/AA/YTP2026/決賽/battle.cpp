#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int h1, h2; cin >> h1 >> h2;
    vector<pair<int, int>> a, b;
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int d,c; cin >> d >> c;
        a.push_back({d, c});
    }
    int m; cin >> m;
    for (int i = 0; i < m; i++)
    {
        int d, c; cin >> d >> c;
        b.push_back({d, c});
    }

    int round = 1;
    while (h1 > 0 || h2 > 0)
    {
        for (auto [d, c] : a)
        {
            if (round % c == 0) h2 -= d;
        }
        if (h2 <= 0)
        {
            cout << 1 << '\n';
            return 0;
        }
        for (auto [d, c] : b)
        {
            if (round % c == 0) h1 -= d;
        }
        if (h1 <= 0)
        {
            cout << 2 << '\n';
            return 0;
        }
        round++;
    }
}