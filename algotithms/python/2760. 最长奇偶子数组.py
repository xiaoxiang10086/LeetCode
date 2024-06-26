class Solution:
    def longestAlternatingSubarray(self, nums: List[int], threshold: int) -> int:
        n = len(nums)
        ans = i = 0
        while i < n:
            if nums[i] > threshold or nums[i]%2:
                i += 1
                continue
            start = i
            i += 1
            while i < n and nums[i] <= threshold and nums[i]%2 != nums[i-1]%2:
                i += 1
            # [start, i-1]
            ans = max(ans, i-start)
        return ans
