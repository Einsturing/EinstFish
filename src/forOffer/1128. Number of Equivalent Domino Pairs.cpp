//难度-简单
//简单哈希表
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<int, int> mp;
        int res = 0;
        for(auto i : dominoes) {
            int id = i[0] > i[1] ? i[1] * 10 + i[0] : i[0] * 10 + i[1];
            res += mp[id];
            mp[id]++;
        }
        return res;
    }
};