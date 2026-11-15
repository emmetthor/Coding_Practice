    /*
    Date: 2026-11-14

    Tags: shortest_path
    Understanding: 
    Implementation: 
    Recognition: 
    Mistakes: 
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
        
        int n, m, q; cin >> n >> m >> q;

        vector<array<ll, 3>> edge(m);
        for (auto &[u, v, w] : edge) cin >> u >> v >> w;

        vector<vector<ll>> floyd(n + 1, vector<ll>(n + 1, 1e18));
        for (auto [u, v, w] : edge)
        {
            floyd[u][v] = min(floyd[u][v], w);
            floyd[v][u] = min(floyd[v][u], w);
        }
        for (int i = 1; i <= n; i++) floyd[i][i] = 0;
        
        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
                }
            }
        }

        for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cerr << floyd[i][j] << " \n"[j == n];

        vector<vector<ll>> visits(q);
        vector<vector<ll>> cnt(n + 1, vector<ll>(n + 1));
        for (auto &vec : visits)
        {
            int l; cin >> l;

            for (int i = 0; i < l; i++)
            {
                ll e; cin >> e;
                vec.push_back(e);
            }
        }
        for (int i = 0; i < q; i++)
        {
            int sz = visits[i].size();
            for (int p = 0; p < sz - 1; p++)
            {
                int pt1 = visits[i][p];
                int pt2 = visits[i][p + 1];
                cnt[pt1][pt2]++;
            }
        }

        ll curr_ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                curr_ans += cnt[i][j] * floyd[i][j];
            }
        }

        cerr << curr_ans << '\n';

        ll min_diff = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                ll diff = 0;
                for (int k = 1; k <= n; k++)
                {
                    if (k == j || k == i) continue;
                    diff += cnt[i][k] * (floyd[j][k] - floyd[i][k]);
                    diff += cnt[k][i] * (floyd[j][k] - floyd[i][k]);
                }
                for (int k = 1; k <= n; k++)
                {
                    if (k == i || k == j) continue;
                    diff += cnt[j][k] * (floyd[i][k] - floyd[j][k]);
                    diff += cnt[k][j] * (floyd[i][k] - floyd[j][k]);
                }

                cerr << i << ' ' << j << ' ' << diff << '\n';

                min_diff = min(min_diff, diff);
            }
        }

        cout << curr_ans + min_diff;
    }