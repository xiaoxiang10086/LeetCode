// 与 「LeetCode 41. 缺失的第一个正数」 是同类型题
class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0 || nums[i] >= n) {
                return -1;
            }
        }
        for (int i = 0; i < n; i++) {
            while (nums[nums[i]] != nums[i]) swap(nums[nums[i]], nums[i]);
            if (nums[i] != i) return nums[i];
        }
        return -1;
    }
};
