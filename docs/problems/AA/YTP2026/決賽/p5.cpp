#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;

int n;
vector<vector<int>> e;

int far = 1;
int far_dis = 0;
void dfs_dist(int u, int p, int dis) {
    if (dis > far_dis) {
        far_dis = dis;
        far = u;
    }
    for (int i : e[u]) {
        if (i != p) {
            dfs_dist(i, u, dis + 1);
        }
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    cin >> n;
    e.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    dfs_dist(1, 1, 0);
    int p1 = far;
    far_dis = 0;
    dfs_dist(p1, p1, 0);
    int p2 = far;

    //cerr << p1 << ' ' << p2 << '\n';

    vector<int> tmp;
    vector<int> path;
    auto find_path = [&](auto self, int x, int p) -> void
    {
        if (x == p2)
        {
            path = tmp;
            path.push_back(x);
            return;
        }
        tmp.push_back(x);
        for (auto y : e[x]) if (y != p) self(self, y, x);
        tmp.pop_back();
    };
    find_path(find_path, p1, p1);

    auto dfs = [&](auto self, int x, int p1, int p2) -> void
    {
        cout << x << ' ';
        for (auto y : e[x])
        {
            if (y == p1 || y == p2) continue;
            self(self, y, x, x);
        }
    };

    int sz = path.size();
    for (int i = 0; i < sz; i++)
    {
        int p1 = (i - 1 >= 0 ? path[i - 1] : 0);
        int p2 = (i + 1 < sz ? path[i + 1] : 0);
        dfs(dfs, path[i], p1, p2);
    }
}