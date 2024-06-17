/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int res;
    int k;

    int kthSmallest(TreeNode* root, int _k) {
        k = _k;
        dfs(root);
        return res;
    }

    void dfs(TreeNode* root) {
        if (!root) return ;
        dfs(root->left);
        if (-- k == 0) {
            res = root->val;
        }
        dfs(root->right);
    }
};
