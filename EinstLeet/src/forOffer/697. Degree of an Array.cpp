//难度-简单
//哈希表存储每个数的频数，首次出现位置和最后一次出现位置
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < len; i++) {
            if(mp.count(nums[i])) {
                mp[nums[i]][0]++;
                mp[nums[i]][2] = i;
            }
            else mp[nums[i]] = {1, i, i};
        }
        int maxFreq = 0, minLen = 0;
        for(auto [num, vec] : mp) {
            if(maxFreq < vec[0]) {
                maxFreq = vec[0];
                minLen = vec[2] - vec[1] + 1;
            }
            else if(maxFreq == vec[0]) minLen = min(minLen, vec[2] - vec[1] + 1);
        }
        return minLen;
    }
};