class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> st;

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        st = vector<bool>(n);
        dfs(nums, 0);
        return res;
    }

    void dfs(vector<int>& nums, int u) {
        if (u == nums.size()) {
            res.push_back(path);
            return ;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!st[i]) {
                path.push_back(nums[i]);
                st[i] = true;
                dfs(nums, u+1);
                st[i] = false;
                path.pop_back();
            }
        }
    }
};
