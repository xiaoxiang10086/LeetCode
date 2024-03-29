class Solution {
public:
    int numSquares(int n) {
        vector<int> f(n+1);
        f[0] = 0;
        for (int i = 1; i <= n; i++) {
            f[i] = i;
            for (int j = 1; j * j <= i; j++) {
                f[i] = min(f[i], f[i-j*j] + 1);
            }
        }
        return f[n];
    }
};
