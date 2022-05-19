//难度-中等
//找到中位数即可
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int res = 0;
        nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
        int mid = nums[nums.size() / 2];
        for(auto num : nums) res += abs(num - mid);
        return res;
    }
};