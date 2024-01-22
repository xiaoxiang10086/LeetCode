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
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        dfs1(root, res);
        return res;
    }
    void dfs1(TreeNode* root, string& res) {
        if (!root) {
            res += "#,";
            return ;
        }
        
        res += to_string(root->val) + ",";
        dfs1(root->left, res);
        dfs1(root->right, res);
    }
    

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int u = 0;
        return dfs2(data, u);
    }
    
    TreeNode* dfs2(string& data, int& u) {
        if (data[u] == '#') {
            u += 2;
            return NULL;
        }
        
        // 8,2,3,#,
        bool is_minus = false;
        int t = 0;
        while (data[u] != ',') {
            if (data[u] == '-') is_minus = true;
            else {
                t = t * 10 + data[u] - '0';
            }
            u ++;
        }
        u ++; //跳过逗号
        if (is_minus) t = -t;
        
        auto root = new TreeNode(t);
        root->left = dfs2(data, u);
        root->right = dfs2(data, u);
        return root;
    }
};