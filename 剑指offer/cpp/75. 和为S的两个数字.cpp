class Solution {
public:
    unordered_set<int> hash;
    vector<int> findNumbersWithSum(vector<int>& nums, int target) {
        for (int x: nums) {
            if(hash.count(target - x)) return {target - x, x};
            hash.insert(x);
        }
        return {-1, -1};
    }
};