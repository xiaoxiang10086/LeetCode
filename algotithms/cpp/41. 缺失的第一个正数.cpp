class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            while (x > 0 && x <= n
                && nums[x-1] != x) {
                    swap(x, nums[x-1]);
                }
        }
        for (int i = 0; i < n; i++)
            if (nums[i] != i+1) {
                return i+1;
            }

        return n+1;
    }
};
