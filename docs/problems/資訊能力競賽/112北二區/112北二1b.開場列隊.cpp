/*
Date: 2026-07-27

Tags: vector
Independent: 5
Understanding: 5
Implementation: 5
Recognition: 5
*/
#include <bits/stdc++.h>
#include <cassert>
using namespace std;

#ifdef LOCAL
    bool debug_mode = 1;
#else
    bool debug_mode = 0;
#endif

using ll = long long;
#define cerr if(debug_mode) cerr

struct Vec
{
    ll x, y;

    Vec operator-(const Vec &b) const
    {
        return Vec{x - b.x, y - b.y};
    }

    Vec operator+(const Vec &b) const
    {
        return Vec{x + b.x, y + b.y};
    }

    bool operator==(const Vec &b) const
    {
        return (x == b.x && y == b.y);
    }
};

ll dot(const Vec &a, const Vec &b)
{
    return a.x * b.x + a.y * b.y;
}

ll cross(const Vec &a, const Vec &b)
{
    return a.x * b.y - b.x * a.y;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n; cin >> n;
    vector<Vec> pp(n); for (auto &[x, y] : pp) cin >> x >> y;

    int root_n = 0;
    while (true)
    {
        Vec root = pp[root_n];
        vector<Vec> vecs;
        for (int i = 0; i < n; i++)
        {
            if (i == root_n) continue;
            vecs.push_back(pp[i] - root);
        }

        int sz = vecs.size();
        Vec team_line = {114514, 0};

        for (int i = 0; i < sz; i++) for (int j = i + 1; j < sz; j++)
        {
            if (cross(vecs[i], vecs[j]) == 0)
            {
                team_line = vecs[i];
                cerr << i << ' ' << j << '\n';
            }
        }

        if (team_line == Vec{114514, 0})
        {
            root_n++;
            continue;
        }

        vector<int> team(n);
        for (int i = 0, j = 0; i < n; i++)
        {
            if (i == root_n)
            {
                team[i] = 0;
                continue;
            }
            if (cross(team_line, vecs[j]) == 0) team[i] = 0;
            else team[i] = 1;
            j++;
        }

        cout << "A\n";
        for (int i = 1; i < n; i++)
        {
            if (team[i] == team[0]) cout << "A\n";
            else cout << "B\n";
        }

        return 0;
    }
}