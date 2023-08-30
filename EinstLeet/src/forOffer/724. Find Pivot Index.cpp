//难度-简单
//accumulate第三个参数是从此初始值开始累加
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int size = nums.size();
        int all = accumulate(nums.begin(), nums.end(), 0);
        int sum = 0;
        for(int i = 0; i < size; i++) {
            if(2 * sum + nums[i] == all) return i;
            sum += nums[i];
        }
        return -1;
    }
};