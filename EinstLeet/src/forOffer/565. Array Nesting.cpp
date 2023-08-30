//难度-中等
//标记遍历即可
class Solution
{
public:
    int arrayNesting(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> vis(n);
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            int j = i;
            while (!vis[j])
            {
                vis[j] = true;
                j = nums[j];
                cnt++;
            }
            res = max(res, cnt);
        }
        return res;
    }
};