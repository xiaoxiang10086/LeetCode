class Solution {
public:
    int maxProductAfterCutting(int n) {
        vector<int> f(n+1);
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) { //最后一段的长度
                f[i] = max(f[i], max(j * (i-j), j * f[i - j]));
            }
        }
        return f[n];
    }
};