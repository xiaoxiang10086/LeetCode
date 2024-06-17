class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        vector<int> left_max(n), right_max(n);
        left_max[0] = h[0], right_max[n-1] = h[n-1];
        for (int i = 1; i < n; i++) {
            left_max[i] = max(left_max[i-1], h[i]);
        }
        for (int i = n-2; i >= 0; i--) {
            right_max[i] = max(right_max[i+1], h[i]);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += min(left_max[i], right_max[i]) - h[i];
        }
        return res;
    }
};