class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> f(n, vector<int>(2));
        f[0][0] = 0, f[0][1] = nums[0];
        for (int i = 1; i < n; i++) {
            f[i][0] = max(f[i-1][0], f[i-1][1]);
            f[i][1] = f[i-1][0] + nums[i];
        }
        return max(f[n-1][0], f[n-1][1]);
    }
};

// 空间优化
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int f = nums[0], g = 0;
        for (int i = 1; i < n; i++) {
            int last_f = f, last_g = g;
            f = g + nums[i];
            g = max(last_g, last_f);
        }
        return max(f, g);
    }
};
