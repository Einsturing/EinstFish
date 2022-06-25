//难度-中等
//dp
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<int> dp(3);
        for(int j = 0; j < 3; j++) dp[j] = costs[0][j];
        for(int i = 1; i < n; i++) {
            vector<int> dpN(3);
            for(int j = 0; j < 3; j++) dpN[j] = min(dp[(j + 1) % 3], dp[(j + 2) % 3]) + costs[i][j];
            dp = dpN;
        }
        return *min_element(dp.begin(), dp.end());
    }
};