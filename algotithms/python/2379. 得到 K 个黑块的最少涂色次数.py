class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        # max(滑动窗口为k的黑色字符个数)
        n = len(blocks)
        ans = max_b = b = 0
        for i in range(n):
            b += blocks[i] == 'B'
            if i < k-1:
                continue
            max_b = max(max_b, b)
            b -= blocks[i-k+1] == 'B'
        return k-max_b
        