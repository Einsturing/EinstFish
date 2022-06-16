//难度-中等
//哈希表存储小的
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_set<int> vis;
        unordered_set<int> res;
        for(int num : nums) {
            if(vis.count(num - k)) res.emplace(num - k);
            if(vis.count(num + k)) res.emplace(num);
            vis.emplace(num);
        }
        return res.size();
    }
};