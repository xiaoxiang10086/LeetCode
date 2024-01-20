class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;

    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return res;
    }

    void dfs(string s, int u) {
        if (u == s.size()) {
            res.push_back(path);
            return ;
        }

        for (int i = u; i < s.size(); i++) {
            if (check(s, u, i)) {
                path.push_back(s.substr(u, i-u+1));
                dfs(s, i+1);
                path.pop_back();
            }
        }
    }

    bool check(string s, int l, int r) {
        for (int i = l, j = r; i < j; i++, j--) {
            if (s[i] != s[j]) return false;
        }
        return true;
    }
};
