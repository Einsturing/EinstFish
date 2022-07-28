//难度-简单
//排序哈希
class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        vector<int> tmp = arr;
        unordered_map<int, int> mp;
        vector<int> res;
        sort(arr.begin(), arr.end());
        for (int i = 0, cnt = 0; i < arr.size(); i++)
            if (!mp.count(arr[i]))
                mp[arr[i]] = cnt++ + 1;
        for (int i = 0; i < tmp.size(); i++)
            res.push_back(mp[tmp[i]]);
        return res;
    }
};