//难度-简单
//简单题
class Solution
{
public:
    vector<int> minSubsequence(vector<int> &nums)
    {
        vector<int> res;
        int cnt = 0;
        sort(nums.begin(), nums.end(), greater<int>());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < nums.size(); i++)
        {
            cnt += nums[i];
            res.emplace_back(nums[i]);
            if (cnt > sum - cnt)
                break;
        }
        return res;
    }
};