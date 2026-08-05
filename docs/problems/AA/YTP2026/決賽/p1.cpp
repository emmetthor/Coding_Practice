#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    const int SZ = 100;

    ll h1, h2; cin >> h1 >> h2;
    ll sum_a[101] = {}, sum_b[101] = {};
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int d,c; cin >> d >> c;
        for (int j = c; j <= SZ; j += c) sum_a[j] += d;
    }
    int m; cin >> m;
    for (int i = 0; i < m; i++)
    {
        int d, c; cin >> d >> c;
        for (int j = c; j <= SZ; j += c) sum_b[j] += d;
    }

    int round = 1;
    while (h1 > 0 || h2 > 0)
    {
        h2 -= sum_a[round % SZ];
        if (h2 <= 0)
        {
            cout << 1 << '\n';
            return 0;
        }
        h1 -= sum_b[round % SZ];
        if (h1 <= 0)
        {
            cout << 2 << '\n';
            return 0;
        }
        round++;
    }
}