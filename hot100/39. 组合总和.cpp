class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(vector<int>& candidates, int u, int sum, int target) {
        if (sum == target) {
            res.push_back(path);
            return ;
        }

        if (u == candidates.size() || sum > target) return ;
        // 不选
        dfs(candidates, u+1, sum, target);

        // 选
        path.push_back(candidates[u]);
        dfs(candidates, u, sum+candidates[u], target);
        path.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, 0, target);
        return res;
    }
};
