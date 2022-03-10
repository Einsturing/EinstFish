//难度-简单
//周赛第一题，贪心即可
class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int maxn = 0;
        int cnt = 0;
        for(auto rec : rectangles) {
            int now = min(rec[0], rec[1]);
            if(now > maxn) {
                maxn = now;
                cnt = 1;
            }
            else if(now == maxn) cnt++;
        }
        return cnt;
    }
};