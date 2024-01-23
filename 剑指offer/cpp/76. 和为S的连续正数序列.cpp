class Solution {
public:
    vector<vector<int> > findContinuousSequence(int sum) {
        vector<vector<int>> res;
        for (int i = 1, j = 1, s = 1; i <= sum; i++) {
            while (s < sum) s += ++ j;
            if (s == sum && j > i) {
                vector<int> tmp;
                for (int k = i; k <= j; k++) tmp.push_back(k);
                res.push_back(tmp);
            }
            s -= i;
        }
        return res;
    }
};
