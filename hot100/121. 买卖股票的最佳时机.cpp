class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minp = INT_MAX;
        int res = 0;
        for (int i = 0; i < prices.size(); i++) {
            res = max(res, prices[i]-minp);
            minp = min(minp, prices[i]);
        }
        return res;
    }
};
