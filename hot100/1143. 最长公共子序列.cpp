class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> f(n+1, vector<int>(m+1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                f[i][j] = max(f[i-1][j], f[i][j-1]);
                if (s1[i - 1] == s2[j-1]) {
                    f[i][j] = max(f[i][j], f[i-1][j-1] + 1);
                }
            }
        }
        return f[n][m];
    }   
};
