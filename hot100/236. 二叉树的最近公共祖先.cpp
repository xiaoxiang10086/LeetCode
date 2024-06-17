/*
函数的含义是在root这棵树找到p和q的最近公共祖先

1、若当前节点root == p，则表示q点一定在root的左右子树其中一处，则最近的公共结点肯定是root
2、若当前节点root == q，则表示p点一定在root的左右子树其中一处，则最近的公共结点肯定是root
3、若1和2情况都不是，则p和q的最近公共祖先要么在root的左子树，要么在root的右子树，则直接递归到root.left和root.right进行搜索，若递归完后，左子树返回null表示没找到，那答案肯定是在右子树，同理，右子树返回null表示没找到，那答案肯定是在左子树
4、若3情况中左右子树都找不到p和q的最近公共祖先，则表示p点和q点分别在不同的左右子树，则root就是他们的最近公共祖先

*/

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        if (root == p || root == q) return root;
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
        if (left == NULL) return right;
        if (right == NULL) return left;
        return root;
    }
};