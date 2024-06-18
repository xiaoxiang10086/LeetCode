class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        # 1 <= a <= b <= c
        # a + b > c
        nums.sort()
        ans = 0
        n = len(nums)
        for k in range(2, n):
            c = nums[k]
            i = 0
            j = k-1
            while i < j:
                if nums[i] + nums[j] > c:
                    ans += j-i
                    j -= 1
                else:
                    i += 1
        return ans
        