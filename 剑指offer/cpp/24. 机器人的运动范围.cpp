class Solution {
public:
    using PII = pair<int, int>;
    
    int get_sum(int x, int y) {
        int res = 0;
        while (x) {
            res += x % 10;
            x /= 10;
        }
        while (y) {
            res += y % 10;
            y /= 10;
        }
        return res;
    } 
    
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    int movingCount(int threshold, int n, int m)
    {
        if (!n || !m) return 0;
        queue<PII> q;
        q.push({0, 0});
        vector<vector<bool>> st(n, vector<bool>(m, false));
        
        int res = 0;
        while (q.size()) {
            PII t = q.front();
            q.pop();
            
            int x = t.first, y = t.second;
            if (st[x][y] || get_sum(x, y) > threshold) continue;
            
            st[x][y] = true;
            res ++;
            
            for (int i = 0; i < 4; i++) {
                int a = x + dx[i], b = y + dy[i];
                if (a < 0 || a >= n || b < 0 || b >= m) continue;
                q.push({a, b});
            }
        }
        return res;
    }

};
