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
    unordered_map<int, int> hash;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if (!n) return NULL;
        for (int i = 0; i < n; i++) {
            hash[inorder[i]] = i;
        }
        return build(preorder, 0, n-1, inorder, 0, n-1);
    }
    
    TreeNode* build(vector<int>& preorder, int pl, int pr, vector<int>& inorder, int il, int ir) {
        if (pl > pr) return NULL;
        auto root = new TreeNode(preorder[pl]);
        int k = hash[root->val];
        root->left = build(preorder, pl+1, pl+(k-il), inorder, il, k-1);
        root->right = build(preorder, pl+(k-il)+1, pr, inorder, k+1, ir);
        return root;
    }
};
