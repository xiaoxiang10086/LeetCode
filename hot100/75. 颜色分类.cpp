class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 全0: [0, j-1]
        // 全1: [j, i-1]
        // 待处理: [i, k]
        // 全2: [k+1, n-1]
        for (int i = 0, j = 0, k = nums.size() - 1; i <= k; ) {
            if (nums[i] == 0) {
                swap(nums[i++], nums[j++]);
            } else if (nums[i] == 1) {
                i++;
            } else {
                swap(nums[i], nums[k--]);
            }
        }
    }
};
