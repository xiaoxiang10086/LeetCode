// 同 「LeetCode 238. 除自身以外数组的乘积」
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int n = A.size();
        if (!n) return {};
        vector<int> p(n, 1);
        for (int i = 1; i < n; i++) {
            p[i] = p[i-1] * A[i-1];
        }
        int end = 1;
        for (int i = n-1; i >= 0; i--) {
            p[i] = p[i] * end;
            end *= A[i];
        }
        return p;
    }
};
