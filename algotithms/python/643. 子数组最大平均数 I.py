class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        ans = -inf
        s = 0
        for i, x in enumerate(nums):
            s += x
            if i < k-1:
                continue
            ans = max(ans, s)
            s -= nums[i-k+1]
        return ans / k
        