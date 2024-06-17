class Solution {
public:
    int minDistance(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> f(n+1, vector<int>(m+1));
        for (int i = 0; i <= n; i++) f[i][0] = i;
        for (int i = 0; i <= m; i++) f[0][i] = i;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int same = (s1[i-1] == s2[j-1] ? 0 : 1);
                f[i][j] = f[i-1][j-1] + same;
                f[i][j] = min(f[i][j], f[i-1][j] + 1);
                f[i][j] = min(f[i][j], f[i][j-1] + 1);
            }
        }
        return f[n][m];
    }
};
