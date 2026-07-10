#include <bits/stdc++.h>
using namespace std;

signed main() {
    /*第一式：一般式*/
    vector<vector<int>> e;
    vector<int> visi;
    queue<int> bfs;
    while (bfs.size()) {
        int x = bfs.front();
        bfs.pop();

        if (visi[x])
            continue;
        visi[x] = 1;

        for (auto i : e[x])
            bfs.push(i);
    }
}
