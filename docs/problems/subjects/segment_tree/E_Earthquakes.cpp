/*
Date: 2026-07-10

Tags: segment_tree
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

const int INF_INF = 2e9;

template<class T, T (*op)(T, T), T (*e)()>
struct SegTree {

    int n;
    vector<T> node;
 
    void set(int L, int R, int id, int p, T &x) {
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
 
    T get(int L, int R, int id, int l, int r) {
        // 不包含，回傳單位元素
        if (r <= L || R <= l) return e();
        // 完全包含，回傳 node
        if (l <= L && R <= r) return node[id];
 
        int mid = (L + R) / 2;
        return op(
            get(L, mid, id * 2, l, r),
            get(mid, R, id * 2 + 1, l, r)
        );
    }

    SegTree(int _n)
    {
        n = 1;
        while (n < _n) n <<= 1;
        node.assign(2 * n, e());
    }

    void set(int p, T x)
    {
        set(0, n, 1, p, x);
    }

    // [l, r)
    T get(int l, int r)
    {
        return get(0, n, 1, l, r);
    }
};

struct State
{
    int building_cnt;
    int mi;
    int minimum_pos;
};

State op(State st1, State st2)
{
    State res{};
    res.building_cnt = st1.building_cnt + st2.building_cnt;

    if (st1.mi < st2.mi)
    {
        res.mi = st1.mi;
        res.minimum_pos = st1.minimum_pos;
    }
    else
    {
        res.mi = st2.mi;
        res.minimum_pos = st2.minimum_pos;
    }

    return res;
}

State e()
{
    return State{0, INF_INF, -1};
}

State make_state(int i, int h)
{
    return State{1, h, i};
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n, m; cin >> n >> m;

    SegTree<State, op, e> seg(n);

    while (m--)
    {
        int type; cin >> type;

        if (type == 1)
        {
            int i, h; cin >> i >> h;
            seg.set(i, make_state(i, h));
        }
        else
        {
            int l, r, p; cin >> l >> r >> p;

            State res = seg.get(l, r);
            int curr_building = res.building_cnt;
            while (res.mi <= p)
            {
                seg.set(res.minimum_pos, e());
                res = seg.get(l, r);
            }

            cout << curr_building - res.building_cnt << '\n';
        }
    }
}