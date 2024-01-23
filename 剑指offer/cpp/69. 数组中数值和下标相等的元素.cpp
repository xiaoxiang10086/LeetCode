class Solution {
public:
    int getNumberSameAsIndex(vector<int>& nums) {
        // [0,   1  2, 3, 4]
        // [-3, -1, 1, 3, 5]
        int n = nums.size();
        int l = 0, r = n-1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] - mid >= 0) r = mid;  // nums[i] - i 数组单调递增
            else l = mid + 1;
        }
        
        if (nums[r] == r) return r;
        return -1;
    }
};
