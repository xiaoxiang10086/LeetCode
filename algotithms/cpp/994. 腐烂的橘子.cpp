class Solution {
public:
    using PII = pair<int, int>;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, n*m));
        queue<PII> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        while (q.size()) {
            auto t = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int a = t.first + dx[i], b = t.second + dy[i];
                if (a < 0 || a >= n || b < 0 || b >= m || grid[a][b] == 0) continue;
                if (dist[a][b] > dist[t.first][t.second] + 1) {
                    dist[a][b] = dist[t.first][t.second] + 1;
                    q.push({a, b});
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) {
                    res = max(res, dist[i][j]);
                } 
            }
        }

        return res == n*m ? -1 : res;
    }
};
