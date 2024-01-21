class Solution {
public:
    int maxProduct(vector<int>& nums) {
    // f[i] = max(a, f[i-1]*a, g[i-1]*a), g[i] = min(a, g[i-1]*a, f[i-1]*a)
        int res = nums[0];
        int f = nums[0], g = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int a = nums[i], fa = f*a, ga = g*a;
            f = max(a, max(fa, ga));
            g = min(a, min(fa, ga));
            res = max(res, f);
        }
        return res;
    }
};
