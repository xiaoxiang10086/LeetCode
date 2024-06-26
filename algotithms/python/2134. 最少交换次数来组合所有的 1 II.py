class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        tot1 = 0
        for x in nums:
            tot1 += (x == 1)
        
        n = len(nums)
        ans = s = 0
        for i in range(n*2):
            s += (nums[i%n] == 1)
            if i < tot1-1:
                continue
            ans = max(ans, s)
            s -= (nums[(i-tot1+1)%n] == 1)
        return tot1-ans
    