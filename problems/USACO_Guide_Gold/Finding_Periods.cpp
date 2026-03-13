/*
Tags: 字串Hash, 枚舉所有因數(公式)

解法：發現只要可以快速比較區間字串是否相同，就可以暴力枚舉題目的方法求解，因此使用 字串 Hash
*/
#include <bits/stdc++.h>
#ifdef LOCAL
    bool Debug = 1;
#else
    bool Debug = 0;
#endif
#define cerr if (Debug) cerr
using namespace std;

struct HashString {
    static const long long m = 1e9 + 7;
    static const long long b = 9973;

    vector<long long> pow = {1};
    vector<long long> hashTable;

    HashString(const string &s) : hashTable(s.size() + 1) {
        while (pow.size() <= s.size()) pow.emplace_back(pow.back() * b % m);

        hashTable[0] = 0;
        for (int i = 0; i < s.size(); i++) {
            hashTable[i + 1] = (hashTable[i] * b % m + (s[i] - 'a')) % m;
        }
    }

    long long getHash(int st, int ed) {
        long long raw = (hashTable[ed + 1] - (hashTable[st] * pow[ed - st + 1]) % m);
        return ((raw % m) + m) % m;
    }
};

signed main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    string s; cin >> s;
    int n = s.size();
    HashString hash(s);

    for (int i = 0; i < n; i++) {
        int curIndex = 0;
        bool valid = true;

        while (curIndex < n) {
            int len = min(i + 1, n - curIndex);
            valid &= (hash.getHash(0, len - 1) == hash.getHash(curIndex, curIndex + len - 1));
            curIndex += len;
        }

        if (valid) cout << i + 1 << ' ';
    }
}