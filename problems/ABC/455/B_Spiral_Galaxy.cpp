// Date: 2026-04-25
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
    
    int h, w; cin >> h >> w;
    vector<string> mp(h); for (auto &s : mp) cin >> s;

    int ans = 0;

    for (int x1 = 0; x1 < h; x1++) {
        for (int y1 = 0; y1 < w; y1++) {
            for (int x2 = x1; x2 < h; x2++) {
                for (int y2 = y1; y2 < w; y2++) {
                    bool valid = 1;

                    for (int xit = x1; xit <= x2 && valid; xit++) {
                        for (int yit = y1; yit <= y2 && valid; yit++) {
                            if (mp[xit][yit] != mp[x1 + x2 - xit][y1 + y2 - yit]) {
                                valid = 0;
                                break;
                            }
                        }
                    }

                    ans += valid;
                }
            }
        }
    }

    cout << ans;
}