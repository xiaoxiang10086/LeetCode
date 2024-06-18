class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        ans = left = 0
        cnt = Counter()
        for right, x in enumerate(nums):
            cnt[x] += 1
            while cnt[x] > k:
                cnt[nums[left]] -= 1
                left += 1
            ans = max(ans, right-left+1)
        return ans
        