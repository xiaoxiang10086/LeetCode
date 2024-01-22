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
    TreeNode* pre = NULL;
    
    TreeNode* convert(TreeNode* root) {
        dfs(root);
        auto p = root;
        while (p && p->left) p = p->left;
        return p;
    }
    
    void dfs(TreeNode* root) {
        if (!root) return ;
        dfs(root->left);
        if (pre != NULL) {
            root->left = pre;
            pre->right = root;
        }
        pre = root;
        dfs(root->right);
    }
    
};
