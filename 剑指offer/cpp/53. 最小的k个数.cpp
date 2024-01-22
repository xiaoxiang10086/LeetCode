class Solution {
public:
    vector<int> getLeastNumbers_Solution(vector<int> input, int k) {
        priority_queue<int> pq; //大根堆
        for (int x: input) {
            pq.push(x);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> res;
        while (pq.size()) {
            res.push_back(pq.top());
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
