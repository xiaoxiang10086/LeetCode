class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hash; //记录前缀和出现次数
        int tot = 0, ans = 0;
        hash[0] = 1;
        for (int x: nums) {
            tot += x;
            ans += hash[tot - k];
            hash[tot] ++;
        }
        return ans;
    }
};
