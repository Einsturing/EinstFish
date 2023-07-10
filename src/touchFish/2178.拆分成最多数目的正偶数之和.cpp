/*
 * @lc app=leetcode.cn id=2178 lang=cpp
 *
 * [2178] 拆分成最多数目的正偶数之和
 */

// @lc code=start
class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        long long start = 2;
        vector<long long> ans;
        if (finalSum % 2 != 0) return ans;
        while (finalSum >= start) {
            finalSum -= start;
            ans.push_back(start);
            start += 2;
        }
        if (finalSum < start) ans[ans.size() - 1] += finalSum;
        return ans;
    }
};
// @lc code=end

