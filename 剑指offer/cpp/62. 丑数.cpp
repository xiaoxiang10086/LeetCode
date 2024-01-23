// 同 「LeetCode 264. 丑数 II」
class Solution {
public:
    int getUglyNumber(int n) {
        vector<int> f(n);
        f[0] = 1;
        for (int i = 1, a = 0, b = 0, c = 0; i < n; i++) {
            int na = f[a] * 2, nb = f[b] * 3, nc = f[c] * 5;
            f[i] = min({na, nb, nc});
            if (f[i] == na) a ++;
            if (f[i] == nb) b ++;
            if (f[i] == nc) c ++;
        }
        return f[n-1];
    }
};
