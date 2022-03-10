//难度-中等
//滑动窗口统计和的最小值，用整个和减去窗口和
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int len = cardPoints.size();
        int window = len - k;
        int sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int tmpsum = accumulate(cardPoints.begin(), cardPoints.begin() + window, 0);
        int minsum = tmpsum;
        for(int i = window; i < len; i++) {
            tmpsum = tmpsum + cardPoints[i] - cardPoints[i - window];
            minsum = min(minsum, tmpsum);
        }
        return sum - minsum;
    }
};