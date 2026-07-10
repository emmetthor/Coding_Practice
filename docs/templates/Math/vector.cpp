struct Vec {
    /*
    儲存點座標 x, y
    也可同時描述向量 (x, y)
    */
    long long x, y;

    Vec (long long _x, long long _y) : x(_x), y(_y) {}

    /*輸出向量 x1 - x0, y1 - y0*/
    Vec operator-(const Vec &b) const {
        return {x - b.x, y - b.y};
    }

    /*向量加法*/
    Vec operator+(const Vec &b) const {
        return {x + b.x, y + b.y};
    }

    double dis() const {
        return {sqrt(x * x + y * y)};
    }

    /*內積：
    判斷點在向量 前/後/過
    判斷垂直 a . b ~ 0
    */
    long long dot (const Vec &b) const {
        return x * b.x + y * b.y;
    }
    
    /*外積：
    判斷點在向量 左/右/過
    共線 AB x AC = 0
    平行 AB x CD = 0
    多邊形面積 1/2 abs (a x b + b x c + ... y x z + z x a)
    */
    long long cross (const Vec &b) const {
        return x * b.y - y * b.x;
    }
};

/*不同風格 dot(a, b) / a.dot(b)*/
inline long long dot (const Vec &a, const Vec &b) {
    return a.dot(b);
}

/*不同風格 cross(a, b) / a.cross(b)*/
inline long long cross(const Vec &a, const Vec &b){
    return a.cross(b);
}

/*點線距 pt 至 ab 線段 (輸入三個點)*/
double dis (Vec pt, Vec a, Vec b) {
    if (dot(b - a, pt - a) <= 0)
        return (a - pt).dis();

    if (dot(a - b, pt - b) <= 0)
        return (b - pt).dis();

    return fabs((double)cross(a - pt, b - pt) / (a - b).dis());
}
