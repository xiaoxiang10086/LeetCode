class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> p(n, 1);
        for (int i = 1; i < n; i++) {
            p[i] = p[i-1] * nums[i-1];
        }
        int end = 1;
        for (int i = n-1; i >= 0; i--) {
            p[i] *= end;
            end *= nums[i];
        }
        return p;
    }
};
