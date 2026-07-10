/*
-Wextra -Wall -Wshadow

-D_GLIBCXX_DEBUG
-DLOCAL
Settings > Compiler > #defines

-std=c++17
Settings > Compiler > Other compiler options

consolas
Settings > Editor > Font
*/

//#pragma GCC optimize("Ofast,unroll-loops") /*送出時再加上*/


#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
bool debug_mode = 1;
#else
bool debug_mode = 0;
#endif // LOCAL

#define rep(i, st, ed) for (int i = (st); i < (ed); i++)
#define all(x) x.begin(), x.end()
#define cerr if(debug_mode) cerr

template<typename t> void debug (t v) {
    if (debug_mode != 1) return;
    cerr << v << ' ';
}
template<typename t> void debug (vector<t> v) {
    if (debug_mode != 1) return;
    for (auto i : v)
        debug(i);
    cerr << '\n';
}
template<typename t> void debug (vector<vector<t>> v) {
    if (debug_mode != 1) return;
    for (auto i : v)
        debug(i);
    cerr << '\n';
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    /*注意送出前要關掉 _GLIBCXX_DEBUG  debug_mode = 1 */
}
