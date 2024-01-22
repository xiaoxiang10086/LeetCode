class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> st;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        st = vector<bool>(nums.size());
        dfs(nums, 0);
        return ans;    
    }

    void dfs(vector<int>& nums, int u) {
        if (u == nums.size()) {
            ans.push_back(path);
            return ;
        }

        for (int i = 0; i < nums.size(); i ++) {
            if (!st[i]) {
                // 上一个元素已经被使用过撤销掉了，当前元素与上一个元素相同就应该被剪枝
                if (i && nums[i] == nums[i - 1] && !st[i - 1]) continue;
                st[i] = true;
                path.push_back(nums[i]);
                dfs(nums, u + 1);
                st[i] = false;
                path.pop_back();
            }
        }
    }
};