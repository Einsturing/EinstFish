//难度-中等
//周赛第二题，暴力n^3会T，想到了用哈希记录，但是用二维数组而不是umap来存导致T了最后几个数据，很可惜
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) for(int j = i + 1; j < nums.size(); j++) mp[nums[i] * nums[j]]++;
        for(auto i : mp) res += i.second * (i.second - 1) / 2;
        return res * 8;
    }
};