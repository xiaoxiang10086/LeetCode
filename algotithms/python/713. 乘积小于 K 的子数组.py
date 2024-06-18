class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        if k <= 1:
            return 0
        ans = left = 0
        prod = 1
        for right, x in enumerate(nums):
            prod *= x
            while prod >= k:  # 不满足要求
                prod /= nums[left]
                left += 1
            ans += right - left + 1
        return ans
        