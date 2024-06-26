class Solution:
    def maxSum(self, nums: List[int], m: int, k: int) -> int:
        ans = s = 0
        n = len(nums)
        cnt = Counter()
        for i in range(n):
            s += nums[i]
            cnt[nums[i]] += 1

            if i < k-1:
                continue
            
            if len(cnt) >= m:
                ans = max(ans, s)
            
            s -= nums[i-k+1]
            cnt[nums[i-k+1]] -= 1
            if cnt[nums[i-k+1]] == 0:
                del cnt[nums[i-k+1]]
        
        return ans
    