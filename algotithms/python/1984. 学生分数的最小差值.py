class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        nums.sort()
        ans = inf
        for i in range(len(nums)):
            if i < k-1:
                continue
            diff = nums[i] - nums[i-k+1]
            if diff < ans:
                ans = diff
        return ans
