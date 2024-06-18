class Solution:
    def maximumBeauty(self, nums: List[int], k: int) -> int:
        nums.sort()
        ans = left = 0
        for right, x in enumerate(nums):
            while x - nums[left] > 2*k:
                left += 1
            ans = max(ans, right-left+1)
        return ans
        