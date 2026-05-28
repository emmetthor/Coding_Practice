// Date: 2026-05-28
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    bool debug_mode = 1;
#else
    bool debug_mode = 0;
#endif

using ll = long long;
#define cerr if(debug_mode) cerr

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int l = i + 1, r = n - 1;
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0)
                {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    r--;
                    l++;
                    while (l < r && nums[l] == nums[l - 1]) l++;
                }
                else if (sum < 0)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }

        return ans;
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    
}