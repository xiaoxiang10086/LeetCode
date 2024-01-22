/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    
    vector<vector<int>> findPath(TreeNode* root, int sum) {
        if (!root) return {};
        dfs(root, sum);
        return res;
    }
    
    void dfs(TreeNode* root, int sum) {
        if (!root) return ;
        sum -= root->val;
        path.push_back(root->val);
        
        if (!sum && !root->left && !root->right) res.push_back(path);
        dfs(root->left, sum), dfs(root->right, sum);
        
        sum += root->val;
        path.pop_back();
    }
    
};
