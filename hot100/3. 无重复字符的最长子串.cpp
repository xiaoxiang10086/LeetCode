class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        unordered_map<char, int> cnt;
        for (int i = 0, j = 0; i < s.size(); i++) {
            cnt[s[i]] ++;
            while (j < i && cnt[s[i]] > 1) {
                cnt[s[j ++]] --;
            }
            res = max(res, i-j+1);
        }
        return res;
    }
};
