/*
Date: 2026-08-26

Tags:
Independent:
Understanding:
Implementation:
Recognition:

Mistakes:
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

struct Trie
{
    int node_cnt = 0;
    vector<array<int, 26>> trie;
    vector<bool> stop;

    Trie(int max_word_len) : trie(max_word_len), stop(max_word_len) {}

    void insert(string s)
    {
        int node = 0;
        for (auto c : s)
        {
            if (trie[node][c - 'a'] == 0) trie[node][c - 'a'] = ++node_cnt;
            node = trie[node][c - 'a'];
        }

        stop[node] = 1;
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    const int MOD = 1e9 + 7;

    string s; cin >> s;
    int n = s.size();

    Trie trie(1e6 + 1);
    int k; cin >> k;
    for (int i = 0; i < k; i++)
    {
        string ss; cin >> ss;
        trie.insert(ss);
    }

    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        int node = 0;
        for (int len = 1; i + len <= n; len++)
        {
            char curr = s[i + len - 1];

            if (trie.trie[node][curr - 'a'] == 0) break;
            node = trie.trie[node][curr - 'a'];

            if (trie.stop[node])
                dp[i + len] = (dp[i + len] + dp[i]) % MOD;
        }
    }

    cout << dp[n];
}