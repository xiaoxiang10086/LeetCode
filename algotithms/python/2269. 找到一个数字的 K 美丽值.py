class Solution:
    def divisorSubstrings(self, num: int, k: int) -> int:
        ans = 0
        s = str(num)
        cur = ""
        for i in range(len(s)):
            cur += s[i]
            if i < k-1:
                continue
            ans += num%int(cur) == 0 if int(cur) != 0 else 0
            cur = cur[1:]
        return ans
