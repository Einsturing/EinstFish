//难度-中等
//双指针维护区间，哈希记录区间内出现次数最大的字母
class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> mp;
        int len = s.length();
        int l = 0, r = 0;
        int maxn = 0;
        while(r < len) {
            mp[s[r]]++;
            maxn = max(maxn, mp[s[r]]);
            if(r - l + 1 - maxn > k) {
                mp[s[l]]--;
                l++;
            }
            r++;
        }
        return r - l;
    }
};