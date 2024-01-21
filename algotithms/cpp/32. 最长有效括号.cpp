class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (stk.empty() || s[i] == '(') stk.push(i);
            else {
                if (s[stk.top()] == '(') {
                    stk.pop();
                    if (!stk.empty()) res = max(res, i - stk.top());
                    else res = max(res, i+1);
                } else {
                    stk.push(i);
                }
            }
        }
        return res;
    }
};
