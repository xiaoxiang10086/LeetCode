class Solution {
public:
    int numberOf1Between1AndN_Solution(int n) {
        // 分类讨论，枚举每一位是 1 的情况
        if (!n) return 0;
        vector<int> number;
        while (n) number.push_back(n%10), n /= 10;   //54321
        int res = 0;
        for (int i = number.size()-1; i >= 0; i--) {
            int lower = 0, higher = 0, t = 1;
            for (int j = i-1; j >= 0; j--) lower = lower * 10 + number[j], t = t * 10;
            for (int j = number.size()-1; j > i; j--) higher = higher * 10 + number[j];
            
            res += higher * t; // 高位: [0, higher-1] 1 低位:[0, t)
            if (number[i] == 1)  res += lower + 1; // 高位: higher 1 低位: [0, lower]
            else if (number[i] > 1) res += t;
        }
        return res;
    }
};
