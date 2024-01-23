// 同「LeetCode 3. 无重复字符的最长子串」
class Solution {
public:
    int longestSubstringWithoutDuplication(string s) {
        if (s.empty()) return 0;
        int n = s.size();
        unordered_map<int, int> hash;
        int res = 0;
        for (int i = 0, j = 0; i < s.size(); i++) {
            hash[s[i]] ++;
            while (j < i && hash[s[i]] > 1) hash[s[j ++]] --;
            res = max(res, i-j+1);
        }
        return res;
    }
};