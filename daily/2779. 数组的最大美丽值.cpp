class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 0;
        for (int i = 0, j = 0; i < n; i++) {
            while (nums[i] - nums[j] > 2 * k) {
                j ++;
            }
            res = max(res, i-j+1);
        }
        return res;
    }
};
