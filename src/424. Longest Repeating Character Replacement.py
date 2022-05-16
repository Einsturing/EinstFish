# 难度-中等
# 双指针维护区间，哈希记录区间内出现次数最大的字母
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        mp = collections.defaultdict(int)
        length = len(s)
        l, r, maxn = 0, 0, 0
        while r < length:
            mp[s[r]] += 1
            maxn = max(maxn, mp[s[r]])
            if r - l + 1 - maxn > k:
                mp[s[l]] -= 1
                l += 1
            r += 1
        return r - l
