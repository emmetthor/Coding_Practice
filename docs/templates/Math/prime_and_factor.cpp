#include <bits/stdc++.h>
using namespace std;

signed main() {
    /*第一式：質數列表*/

    const int SIZE = 1e7;

    vector<bool> p(SIZE, 1);
    p[0] = p[1] = 0;

    for (int i = 2; i * i < SIZE; i++)
        if (p[i] == 1)
            for (int j = i * i; j < SIZE; j += i)
                p[j] = 0;
    /*所有 p[i] = 1 代表 i 是質數*/

    /*第二式：求某數的因數*/

    const int num = 1e12;

    vector<long long> f;
    for (long long i = 1; i * i <= num; i++) {
        if (num % i == 0) {
            f.push_back(i);
            f.push_back(num / i);
        }
    }
    /*f 即是 num 的所有因數*/

    /*第三式：質因數分解*/

    long long num2 = 1e12;

    vector<array<long long, 2>> pf;
    for (long long i = 2; i * i <= num2; i++) {
        int cnt = 0;

        while (num2 % i == 0) {
            num2 /= i;
            cnt++;
        }

        if (cnt)
            pf.push_back({i, cnt});
    }

    if (num > 1)
        pf.push_back({num, 1});
    /*pf 的形式是 {質數，次方數}*/
}
