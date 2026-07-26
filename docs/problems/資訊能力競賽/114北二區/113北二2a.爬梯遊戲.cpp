/*
Date: 2026-07-23

Tags: lower_upper_bound
Independent: 5
Understanding: 5
Implementation: 5
Recognition: 5
*/
#include <algorithm>
#include <bits/stdc++.h>
#include <sstream>
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
    
    int a, b; cin >> a >> b;

    string line;
    getline(cin, line);

    vector<vector<pair<int, int>>> edge(a + 1);

    for (int i = 1; i <= a - 1; i++)
    {
        string line;
        getline(cin, line);
        istringstream iss(line);

        int x;
        while (iss >> x)
        {
            cerr << i << "-[" << x << "]-" << i + 1 << '\n';
            edge[i].push_back({x, i + 1});
            edge[i + 1].push_back({x, i});
        }
    }

    for (int i = 1; i <= a; i++) sort(edge[i].begin(), edge[i].end());

    vector<int> ans(a + 1);

    for (int i = 1; i <= a; i++)
    {
        int curr = i;
        int p = -1;
        while (true)
        {
            auto it = upper_bound(edge[curr].begin(), edge[curr].end(), make_pair(p + 1, -1));
            if (it == edge[curr].end()) break;

            auto [at, to] = *it;

            cerr << curr << " -> " << to << '\n';

            curr = to;
            p = at;
        }

        ans[curr] = i;
    }

    for (int i = 1; i <= a; i++) cout << ans[i] << " \n"[i == a];
}