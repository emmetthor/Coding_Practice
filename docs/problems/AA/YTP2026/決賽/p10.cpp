#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    const int SZ = 100;

    int t;
    cin >> t;
    while(t--){
        ll n,m;
        cin >> n >> m;
        int ans=0;
        for(int i=1;i<=n;i++){
            int sum=1;
            int now=i;
            while(now>0){
                int mods=now%10;
                sum*=mods;
                now/=10;
            }
            if(sum%m==0) ans++;
        }
        cout << ans << "\n";
    }
}