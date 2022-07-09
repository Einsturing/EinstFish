//难度-中等
//动态规划
class Solution
{
public:
    int lenLongestFibSubseq(vector<int> &arr)
    {
        unordered_map<int, int> mp;
        int n = arr.size();
        for (int i = 0; i < n; i++)
            mp[arr[i]] = i;
        vector<vector<int>> dp(n, vector<int>(n));
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i - 1; j >= 0 && arr[j] * 2 > arr[i]; j--)
            {
                int k = -1;
                if (mp.count(arr[i] - arr[j]) != 0)
                    k = mp[arr[i] - arr[j]];
                if (k >= 0)
                    dp[j][i] = max(dp[k][j] + 1, 3);
                res = max(dp[j][i], res);
            }
        }
        return res;
    }
};