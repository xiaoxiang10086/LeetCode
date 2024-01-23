class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(n);
        res[0] = 1;
        int a = 0, b = 0, c = 0;
        for (int i = 1; i < n; i++) {
            int na = res[a] * 2, nb = res[b] * 3, nc = res[c] * 5;
            res[i] = min({na, nb, nc});
            if (res[i] == na) a++;
            if (res[i] == nb) b++;
            if (res[i] == nc) c++;
        }
        return res.back();
    }
};