//难度-简单
//简单题，这难度认真的吗。。。
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int len = nums.size();
        int cnt = 0;
        for(int i = 0; i < len; i++) {
            if(nums[i] == 1) cnt++;
            else {
                res = max(res, cnt);
                cnt = 0;
            }
        }
        res = max(res, cnt);
        return res;
    }
};