class Solution {
public:
    int moreThanHalfNum_Solution(vector<int>& nums) {
        int r, c = 0;
        for (int x: nums) {
            if (!c) {
                r = x;
                c = 1;
            } else {
                if (r == x) c ++;
                else c --;
            }
        }
        return r;
    }
};
