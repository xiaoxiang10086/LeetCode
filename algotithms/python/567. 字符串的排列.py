class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        cnt_s1 = Counter(s1)
        cnt_s2 = Counter()
        n = len(s2)
        m = len(s1)
        for i in range(n):
            cnt_s2[s2[i]] += 1
            if i < m-1:
                continue
            if cnt_s1 == cnt_s2:
                return True
            cnt_s2[s2[i-m+1]] -= 1
            if cnt_s2[s2[i-m+1]] == 0:
                del cnt_s2[s2[i-m+1]]
        return False
    