#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n),b(n),c(n),d(n),e(n);
    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i];
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ll abs_a=abs(a[i]-a[j]);
            ll abs_b=abs(b[i]-b[j]);
            ll abs_c=abs(c[i]-c[j]);
            ll abs_d=abs(d[i]-d[j]);
            ll abs_e=abs(e[i]-e[j]);
            if(max(abs_a,max(abs_b,max(abs_c,max(abs_d,abs_e))))<=k) ans++;
        }
    }
    cout << ans << "\n";
}