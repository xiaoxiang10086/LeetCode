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
    vector<vector<int>> printFromTopToBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while (q.size()) {
            int sz = q.size();
            vector<int> level;
            while (sz--) {
                auto t = q.front();
                q.pop();
                
                level.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            if (++ depth % 2 == 0) reverse(level.begin(), level.end());
            res.push_back(level);
        }
        return res;
    }
};
