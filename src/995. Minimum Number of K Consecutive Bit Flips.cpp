//难度-困难
//利用差分数组表示A[i]翻转次数-A[i-1]反转次数，则累加和为A[i]翻转次数，若当前累加和加上A[i]为0则需要翻转
class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int len = A.size();
        vector<int> diff(len + 1);
        int res = 0, sumReA = 0;
        for(int i = 0; i < len; i++) {
            sumReA += diff[i];
            if((A[i] + sumReA) % 2 == 0) {
                if(i + K > len) return -1;
                res++;
                sumReA++;
                diff[i + K]--;
            }
        }
        return res;
    }
};