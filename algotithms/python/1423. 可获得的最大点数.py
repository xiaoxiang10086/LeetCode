class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        n = len(cardPoints)
        total = sum(cardPoints)
        if n == k:
            return total

        m = n-k
        s = 0
        ans = inf
        for i in range(n):
            s += cardPoints[i]
            if i < m-1:
                continue
            ans = min(ans, s)
            s -= cardPoints[i-m+1]
        
        ans = total - ans
        return ans
    