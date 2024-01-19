class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            int r = target - nums[i];
            if (hash.count(r)) {
                return {hash[r], i};
            }
            hash[nums[i]] = i;
        }
        return {};
    }
};