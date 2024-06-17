class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0], last = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            last = max(nums[i], last + nums[i]);
            res = max(res, last);
        }
        return res;
    }
};
