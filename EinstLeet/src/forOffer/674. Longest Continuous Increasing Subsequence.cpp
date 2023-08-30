//难度-简单
//最长连续上升子序列，话说这画风和前几天相差也太远了吧
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int tmp = 1;
        int res = 1;
        int len = nums.size();
        if(len == 0) return 0;
        for(int i = 0; i < len - 1; i++) {
            if(nums[i + 1] > nums[i]) tmp++;
            else {
                res = max(res, tmp);
                tmp = 1;
            }
        }
        res = max(res, tmp);
        return res;
    }
};