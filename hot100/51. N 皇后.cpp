class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;
    vector<bool> col, dg, udg;

    vector<vector<string>> solveNQueens(int n) {
        col = vector<bool>(n);
        dg = vector<bool>(2*n), udg = vector<bool>(2*n);
        path = vector<string>(n, string(n, '.'));
        dfs(0, n);
        return res;
    }

    void dfs(int i, int n) {
        if (i == n) {
            res.push_back(path);
            return ;
        }

        for (int j = 0; j < n; j++) {
            if (!col[j] && !dg[i+j] && !udg[i-j+n]) {
                col[j] = dg[i+j] = udg[i-j+n] = true;
                path[i][j] = 'Q';
                dfs(i+1, n);
                path[i][j] = '.';
                col[j] = dg[i+j] = udg[i-j+n] = false;
            }
        }
    }
};
