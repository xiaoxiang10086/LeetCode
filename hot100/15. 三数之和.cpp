// 解法1：
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i+1, k = n-1; j < k; j++) {
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                while (j < k-1 && nums[i] + nums[j] + nums[k-1] >= 0) k --;
                if (nums[i] + nums[j] + nums[k] == 0) {
                    res.push_back({nums[i], nums[j], nums[k]});
                } 
            }
        }   
        return res;
    }
};

// 解法2
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int l = i+1, r = n-1;
            
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum > 0) {
                    r --;
                    continue;
                }
                if (sum < 0) {
                    l ++;
                    continue;
                }
                
                // sum = 0 的情况
                res.push_back({nums[i], nums[l], nums[r]});
                do { l ++; } while (l < r && nums[l] == nums[l-1]);
                do { r --; } while (l < r && nums[r] == nums[r+1]);
            }
        }   
        return res;
    }
};
