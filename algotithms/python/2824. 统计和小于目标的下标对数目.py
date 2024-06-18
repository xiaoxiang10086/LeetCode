class Solution:
    def countPairs(self, nums: List[int], target: int) -> int:
        nums.sort()
        n = len(nums)
        ans = i = 0
        j = n-1
        while i < j:
            if nums[i] + nums[j] < target:
                ans += j - i
                i += 1
            else:
                j -= 1
        return ans
        