class Solution:
    def getSubarrayBeauty(self, nums: List[int], k: int, x: int) -> List[int]:
        cnt = [0] * 101
        n = len(nums)
        ans = [0] * (n-k+1)
        for i in range(n):
            cnt[nums[i]] += 1
            if i<k-1:
                continue
            left = x
            for j in range(-50, 0):
                left -= cnt[j]
                if left <= 0:
                    ans[i-k+1] = j
                    break
            cnt[nums[i-k+1]] -= 1
        return ans
