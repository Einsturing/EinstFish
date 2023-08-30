//难度-简单
//哈希
class Solution
{
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr)
    {
        unordered_map<int, int> mp1, mp2;
        for (int num : target)
            mp1[num]++;
        for (int num : arr)
            mp2[num]++;
        if (mp1.size() != mp2.size())
            return false;
        for (auto [k, v] : mp1)
            if (!mp2.count(k) || mp2[k] != v)
                return false;
        return true;
    }
};