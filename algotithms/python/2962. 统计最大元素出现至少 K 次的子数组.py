class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        mx = max(nums)
        ans = cnt_mx = left = 0
        for right, x in enumerate(nums):
            cnt_mx += x == mx
            while cnt_mx == k:
                cnt_mx -= nums[left] == mx
                left += 1
            ans += left
        return ans
        