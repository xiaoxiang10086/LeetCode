class Solution {
public:
    using LL = long long;
    int findNthDigit(int n) {
        // 1. 确定是K位数
        int k = 1;    // 位数 1->2->3->4
        LL start = 1; // 最小的K位数 1 -> 10 -> 100 -> 1000
        LL t = 9;     // K位数的个数, 例如位数为1有1-9这样9个数 9->90->900
        while (n > k * t) {
            n -= k * t;
            k ++;
            start *= 10;
            t *= 10;
        }
        // 2. 确定是K位数中的第几个
        int num = start + (n + k - 1) / k - 1;
        // 3. 确定是数字的第几位
        n = n % k == 0 ? k : n % k; 
        return to_string(num)[n-1] - '0';
    }
};
