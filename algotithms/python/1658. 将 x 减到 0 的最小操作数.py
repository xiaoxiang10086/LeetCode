class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        target = sum(nums) - x
        if target < 0:
            return -1
        
        # nums 中找到一个最长的子数组，元素和为 target
        ans = -1
        left = s = 0
        for right, x in enumerate(nums):
            s += x
            while s > target:
                s -= nums[left]
                left += 1
            if s == target:
                ans = max(ans, right-left+1)
        return -1 if ans < 0 else len(nums) - ans
