class Solution {
public:
    const string letterMaps[10] = {"", "", "abc", "def", 
                                "ghi", "jkl", "mno",
                                "pqrs", "tuv", "wxyz"};

    vector<string> res;
    string path;
    
    void dfs(string digits, int u) {
        if (u == digits.size()) {
            res.push_back(path);
            return ;
        }

        for (auto ch: letterMaps[digits[u] - '0']) {
            path.push_back(ch);
            dfs(digits, u+1);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if (!n) return res;
        dfs(digits, 0);
        return res;
    }
};
