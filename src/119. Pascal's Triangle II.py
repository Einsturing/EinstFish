# 难度-简单
# 杨辉三角简单dp
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        dp = [[1] + [0] * i for i in range(rowIndex + 1)]
        for i in range(rowIndex + 1):
            dp[i][i] = 1
            for j in range(1, i):
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
        return dp[rowIndex]