struct Dijkstra {
    const int INF = 1e9;
    /*e 的儲存是 {點, 權重}*/
    vector<vector<pair<int, int>>> e;
    vector<int> dis;
    vector<int> visi;
    int n;

    Dijkstra(int _n) : n(_n), e(_n + 1) {}

    void add_edge(int x, int y, int v) {
        e[x].push_back({y, v});
    }

    vector<int> shortest_path(int st) {
        /* pool 的儲存是 {權重, 點}*/
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pool;
        
        dis.assign(n + 1, INF);
        visi.assign(n + 1, 0);

        dis[st] = 0;
        pool.push({0, st});
        
        while (pool.size()) {
            auto [v, x] = pool.top();
            pool.pop();

            if (visi[x])
                continue;
            visi[x] = 1;

            for (auto [y, v2] : e[x]) {
                if (dis[y] > v + v2) {
                    dis[y] = v + v2;
                    pool.push({dis[y], y});
                }
            }
        }

        return dis;
    }
};
