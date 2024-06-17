class Solution {
public:
    int n, m;
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(board, i, j, 0, word)) {
                    return true;
                }
            }
        }
        return false;
    }

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    bool dfs(vector<vector<char>>& board, int x, int y, int u, string word) {
        if (u == word.size()-1) {
            return board[x][y] == word[u];
        }

        if (board[x][y] == word[u]) {
            char ch = board[x][y];
            board[x][y] = '.';
            for (int i = 0; i < 4; i++) {
                int a = x + dx[i], b = y + dy[i];
                if (a < 0 || a >= n || b < 0 || b >= m) continue;
                if (board[a][b] == '.') continue;
                if (dfs(board, a, b, u+1, word)) {
                    return true;
                }
            }
            board[x][y] = ch;
        }

        return false;
    }
};
