//难度-困难
//动态规划
class Solution
{
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<vector<int>>> dp(2 * n - 1, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
        dp[0][0][0] = grid[0][0];
        for (int k = 1; k <= 2 * n - 2; k++)
        {
            for (int x1 = max(k - (n - 1), 0); x1 <= min(k, n - 1); x1++)
            {
                int y1 = k - x1;
                if (grid[x1][y1] == -1)
                    continue;
                for (int x2 = x1; x2 <= min(k, n - 1); x2++)
                {
                    int y2 = k - x2;
                    if (grid[x2][y2] == -1)
                        continue;
                    int res = dp[k - 1][x1][x2];
                    if (x1)
                        res = max(res, dp[k - 1][x1 - 1][x2]);
                    if (x2)
                        res = max(res, dp[k - 1][x1][x2 - 1]);
                    if (x1 && x2)
                        res = max(res, dp[k - 1][x1 - 1][x2 - 1]);
                    res += grid[x1][y1];
                    if (x2 != x1)
                        res += grid[x2][y2];
                    dp[k][x1][x2] = res;
                }
            }
        }
        return max(dp[2 * n - 2][n - 1][n - 1], 0);
    }
};