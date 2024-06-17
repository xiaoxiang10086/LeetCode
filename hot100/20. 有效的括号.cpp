class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto c: s) {
            if (c == '(' || c == '{' || c == '[') stk.push(c);
            else {
                if (stk.empty()) return false;
                else {
                    char t = stk.top();
                    if (t == '(' && c == ')' ||
                        t == '[' && c == ']' || 
                        t == '{' && c == '}') stk.pop();
                    else return false;
                }
            }
        }
        return stk.empty();
    }
};
