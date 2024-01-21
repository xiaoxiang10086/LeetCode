class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int k = n-1;
        while (k && nums[k-1] >= nums[k]) k--;
        if (!k) reverse(nums.begin(), nums.end());
        else {
            int t = k;
            while (t+1 < n && nums[t+1] > nums[k-1]) t++;
            swap(nums[k-1], nums[t]);
            reverse(nums.begin() + k, nums.end());
        }
    }
};
