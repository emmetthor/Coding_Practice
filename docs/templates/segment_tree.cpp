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