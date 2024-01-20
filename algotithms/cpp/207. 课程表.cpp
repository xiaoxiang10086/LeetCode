class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        unordered_map<int, vector<int>> g;
        vector<int> d(n);
        for (auto& edge: p) {
            int a = edge[0], b = edge[1];
            g[b].push_back(a);
            d[a] ++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (!d[i]) {
                q.push(i);
            }
        }
        int tot = 0;
        while(q.size()) {
            auto t = q.front();
            q.pop();
            tot ++;
            for (auto u: g[t]) { // t->u
                d[u] --;
                if (d[u] == 0) {
                    q.push(u);
                }
            }
        }
        return tot == n;
    }
};