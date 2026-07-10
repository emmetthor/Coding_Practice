/*
Date: 2026-07-10

Tags: segment_tree
Independent: 3
Understanding: 5
Implementation: 5
Recognition: 5
*/
#include <bits/stdc++.h>
#include <cerrno>
#include <vector>
using namespace std;

#ifdef LOCAL
    bool debug_mode = 1;
#else
    bool debug_mode = 0;
#endif

using ll = long long;
#define cerr if(debug_mode) cerr

template<class T, T (*op)(const T&, const T&), T (*e)()>
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

    void set(int p, T &x)
    {
        set(0, n, 1, p, x);
    }

    // [l, r)
    T get(int l, int r)
    {
        return get(0, n, 1, l, r);
    }
};

const int MAX_K = 300 + 5;

struct State
{
    int stress[MAX_K] = {};
    int counter[MAX_K] = {};

    // 從 [i] stress 開始的 stress[i] 與 counter[i]
};

State op(const State &st1, const State &st2)
{
    State res;
    for (int i = 0; i < MAX_K; i++)
    {
        res.stress[i] = st2.stress[st1.stress[i]];
        res.counter[i] = st1.counter[i] + st2.counter[st1.stress[i]];
    }

    return res;
}

State e()
{
    State res{};

    for (int i = 0; i < MAX_K; i++)
    {
        res.stress[i] = i;
        res.counter[i] = 0;
    }

    return res;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n, k, q; cin >> n >> k >> q;

    SegTree<State, op, e> seg(n);

    for (int i = 0; i < n; i++)
    {
        int ai, bi; cin >> ai >> bi;

        State res = {};
        
        for (int s = 0; s < k; s++)
        {
            int changed_stress = max(0, s + ai - bi);
            if (changed_stress >= k)
            {
                res.counter[s]++;
                res.stress[s] = 0;
            }
            else res.stress[s] = changed_stress;

            cerr << i << ' ' << s << ' ' << (changed_stress >= k ? 0 : changed_stress) << '\n';
        }

        seg.set(i, res);
    }

    while (q--)
    {
        int l, r; cin >> l >> r;

        auto res = seg.get(--l, r);

        cout << res.counter[0] << ' ' << res.stress[0] << '\n';
    }
}