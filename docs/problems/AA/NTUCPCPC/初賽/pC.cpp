#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct LCA
{
    int n;
    const int LOG = 20;
    vector<set<int>> e;
    vector<vector<int>> up;
    vector<int> depth;
    vector<int> pp;
    LCA(int _n) : n(_n), e(_n), up(_n, vector<int>(LOG)), depth(_n), pp(_n) {};

    void add_edge(int u, int v)
    {
        e[u].insert(v);
    }

    void build(int root, int pp)
    {
        auto dfs = [&](auto self, int x, int p) -> void
        {
            up[x][0] = p;
            //cerr << "from " << x << ", jump 2^" << 0 << " is " << p << '\n';
            for (int k = 1; k < LOG; k++)
            {
                up[x][k] = up[up[x][k - 1]][k - 1];
                //cerr << "from " << x << ", jump 2^" << k << " is " << up[x][k] << '\n';
            }

            for (auto y : e[x])
            {
                if (y == p) continue;
                depth[y] = depth[x] + 1;
                self(self, y, x);
            }
        };
        
        dfs(dfs, root, pp);
    }

    int jump(int from, int d)
    {
        for(int k = 0; k < LOG; k++)
        {
            if ((d >> k) & 1)
            {
                from = up[from][k];
            }
        }

        return from;
    }

    int lca(int a, int b)
    {
        if (depth[a] > depth[b]) swap(a, b); // depth[a] < depth[b]
        b = jump(b, depth[b] - depth[a]);

        if (a == b) return a;

        for (int k = LOG - 1; k >= 0; k--)
        {
            if (up[a][k] != up[b][k])
            {
                a = up[a][k];
                b = up[b][k];
            }
        }

        return up[a][0];
    }

    int dis(int a, int b)
    {
        int _lca = lca(a, b);
        return depth[a] - depth[_lca] + depth[b] - depth[_lca] + 1;
    }
};

struct BIT {
    int n;
    vector<ll> b;

    BIT(int _n) : n(_n), b(_n + 1) {};

    void add(int x, ll v) {
        for (; x <= n; x += x & -x) {
            b[x] += v;
        }
    }

    ll sum(int x) {
        ll res = 0;
        for (; x >= 1; x -= x & -x) {
            res += b[x];
        }
        return res;
    }
};


int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n, q; cin >> n >> q;

    LCA lca(n + 1);

    for (int i = 2; i <= n; i++)
    {
        int p; cin >> p;
        lca.add_edge(p, i);
        lca.add_edge(i, p);

        lca.pp[i] = p;
    }

    lca.build(1, 1);

    vector<int> in(n + 1), out(n + 1);
    int tt = 0;
    auto dfs = [&](auto self, int x, int p) -> void
    {
        in[x] = ++tt;
        for (auto y : lca.e[x])
        {
            if (y == p) continue;
            self(self, y, x);
        }
        out[x] = tt;
    };
    dfs(dfs, 1, 1);

    BIT bit(n);

    while (q--)
    {
        char type; cin >> type;
        if (type == '?')
        {
            int a, b; cin >> a >> b;
            int _lca = lca.lca(a, b);
            
            cerr << bit.sum(in[a]) << ' ' << bit.sum(in[b]) << ' ' << bit.sum(in[_lca])<< ' ' << bit.sum(in[lca.pp[_lca]]) << ' ';

            int cantuse = (bit.sum(in[a]) + bit.sum(in[b]) - bit.sum(in[_lca]) - bit.sum(in[lca.pp[_lca]]));
            cerr << cantuse << '\n';
            cout << lca.dis(a, b) - cantuse << '\n';
        }
        else if (type == '*')
        {
            int node; cin >> node;
            bit.add(in[node], +1);
            bit.add(out[node], -1);
        }
    }
}