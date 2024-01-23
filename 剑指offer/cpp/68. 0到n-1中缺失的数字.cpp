class Solution {
public:
    int getMissingNumber(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;
        int l = 0, r = n-1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] != mid) r = mid;
            else l = mid + 1;
        }
        if (nums[r] == r) r ++;
        return r;
    }
};
