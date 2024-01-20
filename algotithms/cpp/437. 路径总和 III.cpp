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
    using LL = long long;
    unordered_map<LL, int> cnt;
    int res = 0;
    int pathSum(TreeNode* root, int targetSum) {
        cnt[0] = 1;
        dfs(root, 0, targetSum);
        return res;
    }

    void dfs(TreeNode* root, LL cur, int sum) {
        if (!root) return ;
        cur += root->val;
        res += cnt[cur - sum];
        cnt[cur] ++;
        dfs(root->left, cur, sum), dfs(root->right, cur, sum);
        cnt[cur] --;
    }
};
