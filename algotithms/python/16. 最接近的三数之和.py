class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        n = len(nums)
        min_diff = inf
        ans = 0
        for i in range(n-2):
            x = nums[i]
            if i > 0 and x == nums[i-1]:
                continue
            
            s = x + nums[i+1] + nums[i+2]
            if s > target:
                if s - target < min_diff:
                    min_diff = s - target
                    ans = s
                break

            s = x + nums[-2] + nums[-1]
            if s < target:
                if target - s < min_diff:
                    min_diff = target - s
                    ans = s
                continue

            j, k = i+1, n-1
            while j < k:
                s = x + nums[j] + nums[k]
                if s == target:
                    return s
                elif s > target:
                    if s - target < min_diff:
                        min_diff = s - target
                        ans = s
                    k -= 1
                elif s < target:
                    if target - s < min_diff:
                        min_diff = target - s
                        ans = s
                    j += 1
        return ans
    