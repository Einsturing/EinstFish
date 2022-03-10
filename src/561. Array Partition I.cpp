//难度-简单
//我写了，一行秒了，有什么好说的
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int i = 0; i < nums.size(); i += 2) res += nums[i];
        return res;
    }
};