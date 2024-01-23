class Solution {
public:
    int merge(vector<int>& nums, int l, int r) {
        if (l >= r) return 0;
        int mid = l + r >> 1;
        int res = merge(nums, l, mid) + merge(nums, mid+1, r);
        
        int i = l, j = mid+1;
        vector<int> tmp;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) tmp.push_back(nums[i ++]);
            else { // nums[i] > nums[j]
                tmp.push_back(nums[j ++ ]);
                res += mid - i + 1;
            }
        }
        while (i <= mid) tmp.push_back(nums[i ++]);
        while (j <= r) tmp.push_back(nums[j ++ ]);
        
        i = l;
        for (int x: tmp) nums[i ++] = x;
        return res;
    }
    
    int inversePairs(vector<int>& nums) {
        return merge(nums, 0, nums.size()-1);
    }
};
