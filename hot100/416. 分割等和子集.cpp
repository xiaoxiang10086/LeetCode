class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto x: nums) sum += x;
        if (sum % 2) return false;
        sum /= 2;

        vector<bool> f(sum+1);
        f[0] = true;

        for (auto v: nums) {
            for (int j = sum; j >= v; j--) {
                f[j] = f[j] | f[j - v];
            }
        }

        return f[sum];
    }
};
