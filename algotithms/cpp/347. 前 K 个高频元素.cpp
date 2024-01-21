// 哈希表+最小堆
class Solution {
public:
    using PII = pair<int, int>;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (int x: nums) {
            cnt[x] ++;
        }
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        for (const auto& [x, c]: cnt) {
            if (pq.size() < k) {
                pq.push({c, x});
            } else if (pq.top().first < c) {
                pq.pop();
                pq.push({c, x});
            }
        }
        vector<int> res;
        while (pq.size()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};


// 哈希表+计数排序
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        for (int x: nums) cnt[x] ++;

        vector<int> s(n+1);     //每个数字出现次数在 [1, n] 之间
        for (const auto& [x, c]: cnt) {
            s[c] ++;
        }
        int t = 0, i = n;
        while (t < k) t += s[i --]; //找到出现次数最多的K个元素的下界

        vector<int> res;
        for (const auto& [x, c]: cnt) {
            if (c > i) {
                res.push_back(x);
            }
        }
        return res;
    }
};
