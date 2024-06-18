class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        n = len(nums)
        ans = n+1
        s = l = 0
        for r, x in enumerate(nums):
            s += x
            while s - nums[l] >= target:
                s -= nums[l]
                l += 1
            if s >= target:
                ans = min(ans, r-l+1)
        return ans if ans <= n else 0
        