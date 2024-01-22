// 同 「LeetCode 400. 第 N 位数字」
class Solution {
public:
    using LL = long long;
    int digitAtIndex(int n) {
        if (!n) return 0;
        int k = 1; 
        LL start = 1, t = 9;
        while (n > k * t) {
            n -= k * t;
            k ++;
            start *= 10;
            t *= 10;
        }
        
        // 假设是 3 位数(k = 3), start = 100, n = 2, 对应的数字应该是 100
        int num = start + (n + k - 1) / k - 1;
        n = n % k == 0 ? k : n % k;
        return to_string(num)[n-1] - '0';
    }
};
