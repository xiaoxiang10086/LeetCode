class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(vector<int>& candidates, int i, int sum, int target) {
        if (sum == target) {
            res.push_back(path);
            return ;
        }

        if (i == candidates.size() || sum > target) return ;

        // 不选，需要找到下一个不同的数字
        for (int j = i+1; j < candidates.size(); j++) {
            if (candidates[j] != candidates[i]) {
                dfs(candidates, j, sum, target);
                break;
            }
        }

        // 选
        path.push_back(candidates[i]);
        dfs(candidates, i+1, sum + candidates[i], target);
        path.pop_back();
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, 0, target);
        return res;
    }
};
