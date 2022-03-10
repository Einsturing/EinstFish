//难度-简单
//把原数组当作哈希表，出现一次加n，小于等于n的就是没出现的
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        vector<int> res;
        for(auto i : nums) {
            int x = (i - 1) % len;
            nums[x] += len;
        }
        for(int i = 0; i < len; i++) if(nums[i] <= len) res.push_back(i + 1);
        return res;
    }
};