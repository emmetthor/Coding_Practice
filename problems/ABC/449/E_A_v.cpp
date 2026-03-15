// Date: 2026-03-14
/*
Tags: BIT, 循環節

解法：對每個數字的出現高度找一次可能的循環節，最後再用 BIT 求出前綴 kth small number 求解

失誤：每個循環節都要有長度，應該要先行判斷
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct BIT {
    int n;
    vector<int> b;
    BIT(int _n) : n(_n), b(n+1,0) {}
    void upd(int x,int v){
        for(; x <= n; x += x & -x) b[x] += v;
    }
    int sum(int x){
        int res=0;
        for(; x; x -= x & -x) res+=b[x];
        return res;
    }
    int kth(int k){
        int curr=0;
        int h=31-__builtin_clz(n);
        for(int i=h;i>=0;i--){
            if(curr + (1<<i) <= n && b[curr+(1<<i)] < k){
                k -= b[curr+(1<<i)];
                curr += 1<<i;
            }
        }
        return curr+1;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m; cin >> n >> m;
    vector<int> a(n+1), cnt(m+1,0);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        cnt[a[i]]++;
    }

    // 把顏色按出現次數放到桶
    vector<vector<int>> v(n+1);
    for(int i=1;i<=m;i++) v[cnt[i]].emplace_back(i);

    // 計算下一個非空桶
    vector<ll> nx(n+1);
    ll la=-1;
    for(int i=0;i<=n;i++){
        if(!v[i].empty()){
            if(la!=-1) nx[la] = i;
            la = i;
        }
    }
    nx[la] = (ll)1e18/m + la + 1;

    // 讀 queries
    int q; cin >> q;
    vector<pair<ll,int>> qu(q);
    for(int i=0;i<q;i++){
        cin >> qu[i].first;
        qu[i].second = i;
    }
    sort(qu.begin(), qu.end());

    vector<int> ans(q);
    int now = 0;
    ll sum = n, sz = 0;

    // 前 n 個直接取原始
    while(now < q && qu[now].first <= n){
        ans[qu[now].second] = a[qu[now].first];
        now++;
    }

    BIT bit(m);
    for(int i=0;i<=n;i++){
        if(!v[i].empty()){
            for(int col : v[i]){
                bit.upd(col,1);
                sz++;
            }
            ll prev_sum = sum;
            sum += (nx[i]-i)*sz;

            while(now < q && qu[now].first <= sum){
                ll x = qu[now].first - prev_sum - 1; // 0-based
                x %= sz; // 保證安全
                ans[qu[now].second] = bit.kth(x+1); // BIT kth 是 1-based
                now++;
            }
        }
    }

    for(int i=0;i<q;i++) cout << ans[i] << '\n';
}