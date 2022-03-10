//难度-简单
//遍历数组修改数字即可
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;
        int len = nums.size();
        for(int i = 0; i < len - 1; i++) {
            if(nums[i] > nums[i + 1]) {
                cnt++;
                if(cnt >= 2) return false;
                if(i > 0 && nums[i + 1] < nums[i - 1]) nums[i + 1] = nums[i];
            }
        }
        return true;
    }
};