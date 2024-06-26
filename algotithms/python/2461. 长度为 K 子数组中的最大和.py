class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        ans = s = 0
        cnt = Counter()
        n = len(nums)
        for i in range(n):
            s += nums[i]
            cnt[nums[i]] += 1
            if i < k-1:
                continue
            if len(cnt) == k:
                ans = max(ans, s)
            
            x = nums[i-k+1]
            s -= x
            cnt[x] -= 1
            if cnt[x] == 0:
                del cnt[x]
        return ans
    