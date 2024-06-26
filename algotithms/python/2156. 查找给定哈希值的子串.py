class Solution:
    def subStrHash(self, s: str, power: int, mod: int, k: int, hashValue: int) -> str:
        n = len(s)
        ans = hash = 0
        pk = pow(power, k-1, mod)
        for i in range(n-1, -1, -1):
            hash = (hash * power + (ord(s[i]) & 31)) % mod
            if n-i < k:
                continue
            if hash == hashValue:
                ans = i
            # i+k-1
            hash = (hash - pk * (ord(s[i+k-1]) & 31)) % mod
        return s[ans:ans+k]
        