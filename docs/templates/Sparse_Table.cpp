template<typename T>
class binary_lifting {
private:
    int n;
    T m; //mod
    int h;
    vector<vector<T>> table;

public:
    int oper(T a, T b) {
        return a < b ? a : b;
    }
    binary_lifting (typename vector<T>::iterator _begin, typename vector<T>::iterator _end) {
        assert(_begin != _end);

        n = _end - _begin;
        h = __lg(n);

        table.assign(h + 1, vector<T>(n));
        table[0].assign(_begin, _end);

        for (int i = 1, len = 1; i <= h; i++, len <<= 1) {
            for (int j = 0; j + len * 2 <= n; j++) {
                table[i][j] = oper(table[i - 1][j], table[i - 1][j + len]);
            }
        }
    }

    void print() {
        for (int i = 1, len = 1; i <= h; i++, len <<= 1) {
            cerr << "len: " << len * 2 << '\t';
            for (int j = 0; j + len * 2 <= n; j++) {
                cerr << table[i][j] << " \n"[j + len * 2 == n];
            }
        }
    }

    T joint_search(int l, int r) {
        if (l == r) return table[0][l];

        int len = __lg(r - l);

        cerr << (1 << len) << '\n';

        return oper(table[len][l], table[len][r - (1 << len) + 1]);
    }

    T disjoint_search(int l, int r) {
        int len = __lg(r - l);

        T ret = 0;

        for (; len >= 0; len--) {
            if (l + (1 << len) <= r) {
                ret += oper(ret, table[len][l]);
                l += (1 << len);
            }

            return ret;
        }
    }

    void set_mod(T _m) {
        m = _m;
    }
};
