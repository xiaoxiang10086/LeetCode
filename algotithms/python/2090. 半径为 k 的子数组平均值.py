class Solution:
    def getAverages(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        ans = [-1]*n
        s = l = 0
        for r in range(n):
            s += nums[r]
            if r-l+1 == 2*k+1:
                ans[(l+r)//2] = s // (2*k+1) # 更新
                s -= nums[l]
                l += 1
            r += 1
        return ans
