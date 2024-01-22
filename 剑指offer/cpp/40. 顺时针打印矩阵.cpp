class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty()) return res;
        int n = matrix.size(), m = matrix[0].size();
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        int d = 1, x = 0, y = 0;
        vector<vector<bool>> st(n, vector<bool>(m));
        for (int i = 0; i < n*m; i++) {
            res.push_back(matrix[x][y]);
            st[x][y] = true;
            int a = x + dx[d], b = y + dy[d];
            if (a < 0 || a >= n || b < 0 || b >= m || st[a][b]) {
                d = (d+1) % 4;
                a = x + dx[d], b = y + dy[d];
            }
            x = a, y = b;
        }
        return res;
    }
};
