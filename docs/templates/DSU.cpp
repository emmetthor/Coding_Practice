struct DSU {
    vector<int> p, sz; /*p[i] := i 的祖先，sz[i]在 i 為樹根時代表大小*/

    DSU(int n) : p(n + 1), sz(n + 1) { /*建構子初始化*/
        for (int i = 0; i <= n; i++) {
            p[i] = i;
            sz[i] = 1;
        }
    }

    int leader(int x) { /*尋找 x 的樹根 + 路徑壓縮*/
        return x != p[x] ? p[x] = leader(p[x]) : x;
    }

    int size(int x) { /*求出 x 那組的大小*/
        return sz[leader(x)];
    }

    bool same(int x, int y) { /*判斷 x 跟 y 是否同組*/
        return leader(x) == leader(y);
    }

    void merge(int x, int y) { /*將 x, y 連在一起*/
        x = leader(x);
        y = leader(y);

        if (x == y)
            return;

        if (sz[x] < sz[y]) /*啟發式合併*/
            swap(x, y);

        sz[x] += sz[y];
        p[y] = x;
    }
};
