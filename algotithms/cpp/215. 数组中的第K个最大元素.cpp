// 最小堆 O(nlogk)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int x: nums) {
            if (pq.size() < k) {
                pq.push(x);
            } else if (pq.top() < x) {
                pq.pop();
                pq.push(x);
            }
        }
        return pq.top();
    }
};

// 快速选择 O(n)
class Solution {
public:
    int quick_select(vector<int>& nums, int l, int r, int k) {
        if (l >= r) return nums[r];
        int i = l-1, j = r+1, x = nums[l + r >> 1];
        while (i < j) {
            while (nums[++ i] > x);
            while (nums[-- j] < x);
            if (i < j) swap(nums[i], nums[j]);
        }

        // nums[j] >= x
        int cnt = j - l + 1;
        if (k <= cnt) return quick_select(nums, l, j, k);
        else return quick_select(nums, j+1, r, k - cnt);
    }

    int findKthLargest(vector<int>& nums, int k) {
        return quick_select(nums, 0, nums.size()-1, k);
    }
};
