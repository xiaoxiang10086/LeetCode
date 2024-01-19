class Solution {
public:
    int maxArea(vector<int>& h) {
        int res = 0;
        for (int i = 0, j = h.size()-1; i < j; ) {
            res = max(res, min(h[i], h[j]) * (j - i));
            if (h[i] <= h[j]) i++;
            else j--;
        }
        return res;
    }
};
