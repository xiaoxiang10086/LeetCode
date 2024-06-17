class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hash(wordDict.begin(), wordDict.end());
        int n = s.size();
        s = " " + s;
        vector<int> f(n+1);
        f[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) { //枚举最后单词t, 区间为[j, i]
                string t = s.substr(j, i-j+1);
                if (hash.count(t)) f[i] |= f[j-1];
            }
        }
        return f[n];
    }
};
