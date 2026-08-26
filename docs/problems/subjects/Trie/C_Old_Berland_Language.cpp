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

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
    int n; cin >> n;
    vector<array<int, 2>> l(n);
    for (int i = 0; i < n; i++)
    {
        l[i][1] = i;
        cin >> l[i][0];
    }

    sort(l.begin(), l.end());

    int node_cnt = 0;
    vector<string> ans(n);
    vector<array<int, 2>> trie(1e6 + 1);
    vector<bool> stop(1e6 + 1);
    vector<int> parent(1e6 + 1);

    auto dfs = [&](auto self, int node) -> void
    {
        if (node == 0) return;

        int p = parent[node];
        cerr << "at " << p << " with " << stop[trie[p][0]] << ' ' << stop[trie[p][1]] << '\n'; 
        if (stop[trie[p][0]] == 1 && stop[trie[p][1]] == 1)
        {
            stop[p] = 1;
            self(self, p);
        }
    }; 

    for (int i = 0; i < n; i++)
    {
        auto [depth, idx] = l[i];
        int node = 0;
        string res = "";
        for (int j = 0; j < depth; j++)
        {
            bool jump = 0;
            for (auto k : {0, 1})
            {
                if (trie[node][k] == 0)
                {
                    trie[node][k] = ++node_cnt;
                    parent[trie[node][k]] = node;
                }
                else if (stop[trie[node][k]])
                {
                    continue;
                }

                node = trie[node][k];
                res += char('0' + k);
                jump = 1;

                break;
            }

            if (!jump)
            {
                cout << "NO"; return 0;
            }
        }

        ans[idx] = res;
        stop[node] = 1;
    
        dfs(dfs, node);
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) cout << ans[i] << '\n';
}