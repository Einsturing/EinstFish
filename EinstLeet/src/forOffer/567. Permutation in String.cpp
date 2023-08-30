//难度-中等
//判断主串里有无模式串的排列，滑动窗口统计出字符种类与次数和模式串相同的字串，若长度相同说明找到
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int pLen = s1.length();
        int tLen = s2.length();
        map<char, int> pfreq;
        map<char, int> tfreq;
        for(int i = 0; i < pLen; i++) pfreq[s1[i]]++;
        int pCount = pfreq.size();
        int l = 0, r = 0;
        int winCount = 0;
        while(r < tLen) {
            if(pfreq[s2[r]] > 0) {
                tfreq[s2[r]]++;
                if(tfreq[s2[r]] == pfreq[s2[r]]) winCount++;
            }
            r++;
            while(pCount == winCount) {
                if(r - l == pLen) return true;
                if(pfreq[s2[l]] > 0) {
                    tfreq[s2[l]]--;
                    if(tfreq[s2[l]] < pfreq[s2[l]]) winCount--;
                }
                l++;
            }
        }
        return false;
    }
};