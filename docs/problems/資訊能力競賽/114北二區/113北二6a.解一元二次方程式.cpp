/*
Date: 2026-07-23

Tags: math
Independent: 5
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

ll gcd(ll a, ll b)
{
    a = abs(a);
    b = abs(b);
    return a ? gcd(b % a, a) : b;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    ll a, b, c; cin >> a >> b >> c;

    ll b2_4ac = b * b - 4 * a * c;

    ll p = 2 * a;
    ll q = -b;
    ll r = 1;
    for (ll i = 2; i <= 60000; i++)
    {
        while (b2_4ac != 0 && b2_4ac % (i * i) == 0)
        {
            r *= i;
            b2_4ac /= (i * i);
        }
    }
    ll s = b2_4ac;

    ll gcd_pqr = gcd(gcd(p, q), r);

    p /= gcd_pqr;
    q /= gcd_pqr;
    r /= gcd_pqr;

    if (s == 0)
    {
        ll gcd_pq = gcd(p, q);
        p /= gcd_pq; q /= gcd_pq;
        if (p == 1) cout << "x=" << q;
        else cout << "x=" << q << '/' << p;
        return 0;
    }

    cout << "x1=";
    if (p != 1) cout << '[';
    if (s == 1) cout << q << '+' << r;
    else
    {
        cout << q << '+';
        if (r != 1) cout << r;
        if (s > 0) cout << "\\sqrt{" << s << "}";
        else cout << "\\sqrt{" << -s << "}i";
    }
    if (p != 1) cout << "]/" << p;
    cout << '\n';
    
    cout << "x2=";
    if (p != 1) cout << '[';
    if (s == 1) cout << q << '-' << r;
    else
    {
        cout << q << '-';
        if (r != 1) cout << r;
        if (s > 0) cout << "\\sqrt{" << s << "}";
        else cout << "\\sqrt{" << -s << "}i";
    }
    if (p != 1) cout << "]/" << p << '\n';
}