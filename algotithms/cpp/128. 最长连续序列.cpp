class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash(nums.begin(), nums.end());
        int res = 0;
        for (auto num: hash) {
            if (hash.find(num-1) == hash.end()) {
                int end = num;
                while (hash.find(end) != hash.end()) {
                    end ++;
                }
                res = max(res, end - num);
            }
        }
        return res;
    }
};
