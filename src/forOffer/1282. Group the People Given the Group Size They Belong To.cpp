//难度-中等
//哈希表
class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {
        unordered_map<int, vector<int>> mp;
        int n = groupSizes.size();
        for (int i = 0; i < n; i++)
        {
            int size = groupSizes[i];
            mp[size].emplace_back(i);
        }
        vector<vector<int>> res;
        for (auto &[size, idxs] : mp)
        {
            int cnt = idxs.size() / size;
            for (int i = 0; i < cnt; i++)
            {
                vector<int> group;
                int start = i * size;
                for (int j = 0; j < size; j++)
                    group.emplace_back(idxs[start + j]);
                res.emplace_back(group);
            }
        }
        return res;
    }
};