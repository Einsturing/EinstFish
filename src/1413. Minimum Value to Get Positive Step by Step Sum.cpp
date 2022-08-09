//难度-简单
//简单题
class Solution
{
public:
    int minStartValue(vector<int> &nums)
    {
        int start = 1;
        int cnt = start;
        for (int i = 0; i < nums.size(); i++)
        {
            cnt += nums[i];
            if (cnt < 1)
            {
                start += 1 - cnt;
                cnt += 1 - cnt;
            }
        }
        return start;
    }
};