//难度-困难
//转换成求最多存在K个不同整数的子区间的个数减去最多存在K-1个不同整数的子区间的个数
class Solution {
public:
    int cal(vector<int> A, int K) {
        int len = A.size();
        map<int, int> mp;
        int left = 0;
	    int right = 0;
	    int cnt = 0;
	    int res = 0;
        while(right < len) {
		    if(mp[A[right]] == 0) cnt++;
		    mp[A[right]]++;
		    right++;
		    while(cnt > K) {
			    mp[A[left]]--;
			    if(mp[A[left]] == 0) cnt--;
			    left++;
		    }
		    res += right - left;
	    }
	    return res;
    }
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return cal(A, K) - cal(A, K - 1);
    }
};