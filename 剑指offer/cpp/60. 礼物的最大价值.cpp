// 同「LeetCode 64. 最小路径和」
class Solution {
public:
    int getMaxValue(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> f(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!i && !j) f[i][j] = grid[i][j];
                if (i) f[i][j] = max(f[i][j], f[i-1][j] + grid[i][j]);
                if (j) f[i][j] = max(f[i][j], f[i][j-1] + grid[i][j]);
            }
        }
        return f[n-1][m-1];
    }
};
