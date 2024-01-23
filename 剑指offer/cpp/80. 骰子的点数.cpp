class Solution {
public:
    vector<int> numberOfDice(int n) {
        vector<vector<int>> f(n+1, vector<int>(6*n+1)); // f[i][j] 投掷i次总和是j的方案数
        f[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 6 * n; j++) {
                for (int k = 1; k <= min(6, j); k++) {
                    f[i][j] += f[i-1][j - k];
                }
            }
        }
        vector<int> res;
        for (int i = n; i <= 6 * n; i++) res.push_back(f[n][i]);
        return res;
    }
};
