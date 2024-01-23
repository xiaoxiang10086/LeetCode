class Solution {
public:
    int maxDiff(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;
        int minp = nums[0];
        int res = 0;
        for (int i = 1; i < n; i++) {
            res = max(res, nums[i] - minp);
            minp = min(minp, nums[i]);
        }
        return res;
    }
};
