// Date: 2026-03-22
// Tags: 暴力, 觀察
/*
解法：請見 ChatGPT
*/
#include <bits/stdc++.h>
using namespace std;

int digit_sum(int x) {
    int res = 0;
    while (x > 0) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

string build_chain(int x) {
    string res;
    while (true) {
        res += to_string(x);
        if (x <= 9) break;
        x = digit_sum(x);
    }
    return res;
}

void solve() {
    string s;
    cin >> s;
    int n = (int)s.size();

    vector<int> cnt(10, 0);
    int total_sum = 0;
    for (char c : s) {
        cnt[c - '0']++;
        total_sum += c - '0';
    }

    for (int x = 1; x <= 9 * n; x++) {
        string chain = build_chain(x);

        vector<int> need(10, 0);
        int chain_sum = 0;
        for (char c : chain) {
            need[c - '0']++;
            chain_sum += c - '0';
        }

        bool ok = true;
        for (int d = 0; d <= 9; d++) {
            if (need[d] > cnt[d]) {
                ok = false;
                break;
            }
        }
        if (!ok) continue;

        int remain_sum = total_sum - chain_sum;
        int remain_cnt = 0;
        for (int d = 0; d <= 9; d++) {
            remain_cnt += cnt[d] - need[d];
        }

        if (!(remain_cnt == 0 || remain_sum == x)) continue;

        string pref = "";
        for (int d = 9; d >= 0; d--) {
            pref += string(cnt[d] - need[d], char('0' + d));
        }

        cout << pref + chain << '\n';
        return;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}