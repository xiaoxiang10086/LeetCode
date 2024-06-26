class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        # s >= k * threshold
        ans = s = 0
        for i in range(len(arr)):
            s += arr[i]
            if i < k-1:
                continue
            if s >= k * threshold:
                ans += 1
            s -= arr[i-k+1]
        return ans
        
