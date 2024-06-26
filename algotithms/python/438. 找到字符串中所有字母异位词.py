class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        ans = []
        cnt_p = Counter(p)
        cnt_s = Counter()
        n = len(s)
        m = len(p)
        for i in range(n):
            cnt_s[s[i]] += 1
            if i < m-1:
                continue
            if cnt_s == cnt_p:
                ans.append(i-m+1)
            cnt_s[s[i-m+1]] -= 1
            if cnt_s[s[i-m+1]] == 0:
                del cnt_s[s[i-m+1]]
        return ans
        