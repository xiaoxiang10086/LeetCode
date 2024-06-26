class Solution:
    def countCompleteSubstrings(self, word: str, k: int) -> int:
        def f(s: str) -> int:
            # s 中有多少个子串，其每个字母恰好出现 k 次
            # 枚举子串中有多少种字母 m
            # 长度恰好为 m*k 的窗口内，是否满足每个字母恰好出现 k 次

            res = 0
            for m in range(1, 27):
                size = m*k
                if size > len(s):
                    break
                
                cnt = Counter()
                for i in range(len(s)):
                    cnt[s[i]] += 1
                    if i < size-1:
                        continue
                    
                    res += all(c == k for c in cnt.values())

                    cnt[s[i-size+1]] -= 1
                    if cnt[s[i-size+1]] == 0:
                        del cnt[s[i-size+1]]

            return res
        
        # 分组循环: https://leetcode.cn/problems/longest-even-odd-subarray-with-threshold/solutions/2528771/jiao-ni-yi-ci-xing-ba-dai-ma-xie-dui-on-zuspx/
        n = len(word)
        ans = i = 0
        while i < n:
            start = i
            i += 1
            while i < n and abs(ord(word[i-1]) - ord(word[i])) <= 2:
                i += 1
            ans += f(word[start:i])
        return ans
    