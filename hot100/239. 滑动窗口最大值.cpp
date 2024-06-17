class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (q.size() && i-q.front()+1 > k) q.pop_front();
            while (q.size() && nums[i] >= nums[q.back()]) q.pop_back();
            q.push_back(i);
            if (i >= k-1) res.push_back(nums[q.front()]);
        }
        return res;
    }
};
