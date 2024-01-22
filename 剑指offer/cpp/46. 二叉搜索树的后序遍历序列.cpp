class Solution {
public:
    bool verifySequenceOfBST(vector<int> sequence) {
        if (sequence.empty()) return true;
        return dfs(sequence, 0, sequence.size()-1);
    }
    bool dfs(vector<int>& seq, int l, int r) {
        if (l >= r) return true;
        int root = seq[r];
        int k = l;
        while (k < r && seq[k] < root) k ++; // 左子树 [l, k-1]
        for (int i = k; i < r; i++) {   // 右子树 [k, r-1]
            if (seq[i] < root) {
                return false;
            }
        }
        return dfs(seq, l, k-1) && dfs(seq, k, r-1);
    }
};
