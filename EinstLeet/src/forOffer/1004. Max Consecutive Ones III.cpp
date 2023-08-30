//难度-中等
//翻转0和1，滑动窗口统计前缀和，前缀和之差大于K表示不可行，窗口左端点右移
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int len = A.size();
        int res = 0, lsum = 0, rsum = 0;
        int left = 0;
        for(int right = 0; right < len; right++) {
            rsum += 1 - A[right];
            while(rsum - lsum > K) {
                lsum += 1 - A[left];
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};