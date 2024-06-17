class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> stk;
        vector<int> res(T.size());
        for (int i = T.size() - 1; i >= 0; i--) {
            while (stk.size() && T[i] >= T[stk.top()]) stk.pop();
            if (stk.size()) {
                res[i] = stk.top() - i;
            } 
            stk.push(i);
        }
        return res;
    }
};
