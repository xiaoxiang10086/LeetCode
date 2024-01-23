class Solution {
public:
    string leftRotateString(string str, int n) {
        int m = str.size() - n;
        reverse(str.begin(), str.end());
        reverse(str.begin(), str.begin() + m);
        reverse(str.begin() + m, str.end());
        return str;
    }
};
