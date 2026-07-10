#include <bits/stdc++.h>
using namespace std;

signed main() {
    /*第一式：樹的拜訪*/
    vector<vector<int>> e;
    auto dfs = [&](auto self, int x, int lst) -> void {
        for (auto i : e[x]) {
            if (i == lst)
                continue;
            self(self, i, x);
        }
    };

    /*第二式：一般式*/
    vector<int> visi;
    auto dfs2 = [&](auto self, int x) -> void {
        if (visi[x])
            return;
        visi[x] = 1;

        for (auto &i : e[x])
            self(self, i);
    };

    /*第三式：Flood Fill algorithm*/
    int n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (visi[i])
            continue;
        ans++;
        dfs2(dfs2, i);
    }

    /*第四式：樹壓平*/
    vector<int> l, r;
    int id = 0;
    auto dfs3 = [&](auto self, int x, int lst) -> void {
        l[x] = ++id; /* 注意這裡一定要使用 ++id*/
        for (auto i : e[x]) {
            if (x == lst)
                continue;
            self(self, i, x);
        }
        r[x] = id;
    };

    /*第五式：有向圖找環*/
    vector<int> in_way;
    bool is_there_a_circle = 0;
    auto dfs4 = [&](auto self, int x) -> void {
        if (visi[x])
            return;
        visi[x] = 1;

        in_way[x] = 1;
        for (auto &i : e[x]) {
            if (in_way[i] == 1) {
                is_there_a_circle = 1;
                exit(0);
            }

            self(self, i);
        }
        in_way[x] = 0;
    };

    /*第六式：無向圖找環*/
    auto dfs5 = [&](auto self, int x) -> void {
        if (visi[x]) {
            is_there_a_circle = 1;
            exit(0);
        }
        visi[x] = 1;

        for (auto i : e[x])
            self(self, x);
    };
}
