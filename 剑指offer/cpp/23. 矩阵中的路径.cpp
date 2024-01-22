// 同 「LeetCode 79. 单词搜索」
class Solution {
public:
    int n, m;
    bool hasPath(vector<vector<char>>& matrix, string &str) {
        n = matrix.size();
        if (!n) return false;
        m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(matrix, i, j, str, 0)) return true;
            }
        }
        return false;
    }
    
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    bool dfs(vector<vector<char>>& matrix, int x, int y, string& str, int u) {
        if (u == str.size()-1) {
            return matrix[x][y] == str[u];
        }
        
        if (u >= str.size() || matrix[x][y] != str[u]) return false;
        
        char ch = matrix[x][y];
        matrix[x][y] = '.';
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= m || matrix[a][b] == '.') continue;
            if (dfs(matrix, a, b, str, u+1)) return true;
        }
        matrix[x][y] = ch;
        
        return false;
    }
};
