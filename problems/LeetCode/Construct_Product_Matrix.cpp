// Date: 2026-03-24
// Tags: 前綴和
/*
解法：
把矩陣拉成一維陣列，會發現其實 ans 的每一項都會是前綴 * 後綴，就可以解題
*/
#include <vector>

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> ans(n, vector<int>(m));

        auto idx = [&](int id) -> pair<int, int> {
            return {id / m, id % m};
        };
        auto to_id = [&](int r, int c) -> int {
            return r * m + c;
        };

        vector<long long> prefix(n * m + 1), suffix(n * m + 1);
        prefix[0] = grid[0][0];
        for (int i = 1; i < n * m; i++) {
            auto [r, c] = idx(i);
            prefix[i] = (prefix[i - 1] * (grid[r][c] % 12345)) % 12345;
        }
        suffix[n * m - 1] = grid[n - 1][m - 1];
        for (int i = n * m - 2; i >= 0; i--) {
            auto [r, c] = idx(i);
            suffix[i] = (suffix[i + 1] * (grid[r][c] % 12345)) % 12345;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int id = to_id(i, j);
                ans[i][j] = ((id - 1 >= 0 ? prefix[id - 1] : 1) * (id + 1 < n * m ? suffix[id + 1] : 1)) % 12345;
            }
        }

        return ans;
    }
};