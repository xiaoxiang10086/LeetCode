class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int n, m;

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    cnt ++;
                }
            }
        }    
        return cnt;
    }

    void dfs(vector<vector<char>>& g, int x, int y) {
        g[x][y] = '0';
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < m && g[a][b] == '1') {
                dfs(g, a, b);
            }
        }
    }
};
