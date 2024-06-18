class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        cnt0 = 0
        ans = left = 0
        for right, x in enumerate(nums):
            cnt0 += x == 0
            while cnt0 > k:
                cnt0 -= nums[left] == 0
                left += 1
            ans = max(ans, right-left+1)
        return ans
