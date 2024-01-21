class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last = 0; // 第一次到达 i 上一步的位置
        for (int i = 1; i < nums.size(); i++) {
            while (last < i && i > nums[last] + last) last ++;
            if (last == i) return false;
        }
        return true;
    }
};
