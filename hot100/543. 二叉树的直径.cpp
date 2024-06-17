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
    int res = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return res;
    }

    // 返回「从当前节点到叶子节点的最大长度」
    int dfs(TreeNode* root) {
        if (!root) return -1;
        int left = dfs(root->left);
        int right = dfs(root->right);
        res = max(res, left + right + 2);
        return max(left, right) + 1;
    }
};
