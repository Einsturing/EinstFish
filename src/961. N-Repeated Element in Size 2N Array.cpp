//难度-简单
//遍历查询即可
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        map<int, int> mp;
        int n = nums.size() / 2;
        int cnt = 0;
        int res;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
            if(mp[nums[i]] > cnt) {
                cnt = mp[nums[i]];
                res = nums[i];
            }
            if(cnt == n) return nums[i];
        }
        return res;
    }
};