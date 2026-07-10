struct Fraction {
    long long num, den; /*num 分子, den 分母*/

    long long _gcd(long long a, long long b) {
        return a ? _gcd(b % a, a) : b;
    }

    Fraction (long long n = 0LL, long long d = 1LL) : num(n), den(d) {
        if (den < 0) {
            num *= -1;
            den *= -1;
        }

        long long g = _gcd(num, den);
        num /= g;
        den /= g;
    }

    bool operator<(const Fraction b) const {
        return num * b.den < den * b.num;
    }

    bool operator==(const Fraction b) const {
        return num * b.den == den * b.num;
    }

    Fraction operator+(const Fraction b) const {
        return Fraction(b.den * num + den * b.num, den * b.den);
    }

    Fraction operator-(const Fraction b) const {
        return Fraction(b.den * num - den * b.num, den * b.den);
    }

    Fraction operator*(const Fraction b) const {
        return Fraction(num * b.num, den * b.den);
    }

    Fraction operator/(const Fraction b) const {
        return Fraction(num * b.den, den * b.num);
    }

    /*定義分數可以使用 Fraction A(1, 2) => 二分之一*/
};
