class Solution {
public:
    using LL = long long;
    double Power(double x, int n) {
        bool is_minus = n < 0;
        double res = 1;
        LL k = abs(LL(n)); // n 可能取到 INT_MIN, 取绝对值会溢出
        while (k > 0) {
            if (k & 1) res = res * x;
            x *= x;
            k >>= 1;
        }
        return is_minus ? 1 / res : res;
    }
};
