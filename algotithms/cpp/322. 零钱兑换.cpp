class Solution {
public:
    int coinChange(vector<int>& coins, int m) {
        vector<int> f(m+1, 1e8);
        f[0] = 0;
        for (int v: coins) {
            for (int j = v; j <= m; j++) {
                f[j] = min(f[j], f[j-v] + 1);
            }
        }
        return f[m] == 1e8 ? -1 : f[m];
    }
};
