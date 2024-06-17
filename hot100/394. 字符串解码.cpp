// 题解: https://www.acwing.com/solution/content/5575/

// 1. 栈模拟
class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> strs;
        int num = 0;
        int n = s.size();
        string res;
        for (int i = 0; i < n; i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + (s[i] - '0');
            } else if (s[i] >= 'a' && s[i] <= 'z') {
                res += s[i];
            } else if (s[i] == '[') {
                nums.push(num);
                strs.push(res);
                num = 0;
                res = "";
            } else if (s[i] == ']') {
                int cnt = nums.top(); nums.pop();
                // 此时 tmp 是括号外的字符
                string tmp = strs.top(); strs.pop();
                // 这里分配的是括号内的字符
                for (int i = 0; i < cnt; i++) {
                    tmp += res;
                }
                res = tmp;
            }
        }
        return res;
    }
};

// 2. 递归
class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        string ans;
        for (int i = 0; i < n; ) {
            if (isdigit(s[i])) {
                int j = i;
                int t = 0;
                while (isdigit(s[j])) {
                    t = t * 10 + s[j] - '0';
                    j ++;
                }

                i = ++ j;
                int cnt = 1;
                while (cnt > 0) {
                    if (s[j] == '[') cnt ++;
                    else if (s[j] == ']') cnt --;
                    j ++;
                }

                string res = decodeString(s.substr(i, j-i-1));
                while (t--) ans += res;
                i = j;
            } else {
                ans += s[i];
                i ++;
            }
        }

        return ans;
    }
};
