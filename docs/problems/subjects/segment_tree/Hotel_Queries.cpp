/*
Date: 2026-07-10

Tags: segment_tree, binary_search_on_segment_tree
Independent: 3
Understanding: 5
Implementation: 5
Recognition: 5
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

template<class T, T (*op)(T, T), T (*e)()>
struct SegTree {

    int n;
    vector<T> node;
 
    void set(int L, int R, int id, int p, T &x)
    {
        if (L + 1 == R)
        {
            node[id] = x;
            return;
        }
 
        int mid = (L + R) / 2;
 
        if (p < mid)
        {
            set(L, mid, id * 2, p, x);
        }
        else
        {
            set(mid, R, id * 2 + 1, p, x);
        }
 
        node[id] = op(node[id * 2], node[id * 2 + 1]);
    }

    void sub(int L, int R, int id, int p, T &x)
    {
        if (L + 1 == R)
        {
            node[id] -= x;
            return;
        }
 
        int mid = (L + R) / 2;
 
        if (p < mid)
        {
            sub(L, mid, id * 2, p, x);
        }
        else
        {
            sub(mid, R, id * 2 + 1, p, x);
        }
 
        node[id] = op(node[id * 2], node[id * 2 + 1]);
    }

    int search(int L, int R, int id, T &x)
    {
        if (L + 1 == R) return L;

        int mid = (L + R) / 2;

        if (node[id * 2] >= x)
        {
            return search(L, mid, id * 2, x);
        }
        else
        {
            return search(mid, R, id * 2 + 1, x);
        }
    }

    SegTree(int _n)
    {
        n = 1;
        while (n < _n) n <<= 1;
        node.assign(2 * n, e());
    }

    void set(int p, T &x)
    {
        set(0, n, 1, p, x);
    }

    int search(T &x)
    {
        if (node[1] < x) return -1;
        return search(0, n, 1, x);
    }

    void sub(int p, T &x)
    {
        sub(0, n, 1, p, x);
    }
};

int op(int a, int b)
{
    return max(a, b);
}

int e()
{
    return -1e9;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n, m; cin >> n >> m;

    SegTree<int, op, e> seg(n);

    for (int i = 0; i < n; i++)
    {
        int ai; cin >> ai;
        seg.set(i, ai);
    }

    while (m--)
    {
        int x; cin >> x;
        int res = seg.search(x);

        cout << res + 1 << " \n"[m == 0];

        if (res >= 0) seg.sub(res, x);
    }
}