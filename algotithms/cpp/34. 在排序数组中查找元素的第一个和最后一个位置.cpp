class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int n = nums.size();
        if (!n) return {-1, -1};
        int l = 0, r = n-1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        if (nums[r] != target) return {-1, -1};
        else {
            res.push_back(l);
            l = 0, r = n-1;
            while (l < r) {
                int mid = l + r + 1 >> 1;
                if (nums[mid] <= target) l = mid;
                else r = mid - 1;
            }
            res.push_back(r);
            return res;
        }
    }
};
