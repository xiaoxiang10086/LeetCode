// 同 「LeetCode 160. 相交链表」
class Solution {
public:
    int getNumberOfK(vector<int>& nums, int k) {
        int n = nums.size();
        if (!n) return 0;
        int l = 0, r = n-1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= k) r = mid;
            else l = mid + 1;
        }
        if (nums[r] != k) return 0;
        int tmpl = l;
        l = 0, r = n-1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (nums[mid] <= k) l = mid;
            else r = mid - 1;
        }
        return r-tmpl+1;
    }
};
