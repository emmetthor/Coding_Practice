template<typename T>
class BIT {
private:
    int n;
    vector<T> b;

public:
    BIT(int _n) : n(_n), b(_n) {};

    // 更新位於 x 的值 (加上 v)
    void upd(int x, T v) {
        for (; x < n; x += x & -x) {
            b[x] += v;
        }
    }

    // 計算 1 ~ x 的前綴和
    T sum(int x) {
        T res = 0;
        for (; x; x -= x & -x) {
            res += b[x];
        }
        return res;
    }
};
