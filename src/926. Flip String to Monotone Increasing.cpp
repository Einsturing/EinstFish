//难度-中等
//动态规划
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int dp0 = 0, dp1 = 0;
        for(char c : s) {
            int dpi0 = dp0, dpi1 = min(dp0, dp1);
            if(c == '1') dpi0++;
            else dpi1++;
            dp0 = dpi0;
            dp1 = dpi1;
        }
        return min(dp0, dp1);
    }
};