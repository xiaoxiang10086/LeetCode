// 同 「LeetCode 47. 全排列 II」
class Solution {
public:
    vector<vector<int>> res;
    vector<bool> st;
    vector<int> path;
    
    vector<vector<int>> permutation(vector<int>& nums) {
        if (nums.empty()) return res;
        sort(nums.begin(), nums.end());
        st = vector<bool>(nums.size());
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
                // 上一个元素已经被使用过撤销掉了，当前元素与上一个元素相同就应该被剪枝
                if (i && nums[i] == nums[i-1] && !st[i-1]) continue;
                st[i] = true;
                path.push_back(nums[i]);
                dfs(nums, u+1);
                path.pop_back();
                st[i] = false;
            }
        }
    }
};