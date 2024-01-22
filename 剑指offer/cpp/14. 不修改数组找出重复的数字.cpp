class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        int l = 1, r = nums.size() - 1;     // [1, n]
        while (l < r) {
            int mid = l + r >> 1;   // 划分的区间：[l, mid], [mid + 1, r]
            int s = 0;
            for (int x: nums) s += (x >= l && x <= mid); 
            if (s > mid-l+1) r = mid;
            else l = mid + 1;
        }
        return r;
    }
};
