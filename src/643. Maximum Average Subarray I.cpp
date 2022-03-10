//难度-简单
//滑动窗口变头尾即可
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        for(int i = 0; i < k; i++) sum += nums[i];
        double maxAverage = sum / k;
        for(int i = 0; i + k < nums.size(); i++) {
            sum -= nums[i];
            sum += nums[i + k];
            maxAverage = max(maxAverage, sum / k);
        }
        return maxAverage;
    }
};