//难度-简单
//简单模拟题，话说随到简单题是不是应该加一题
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> flag;
        int num = 0;
        for(int i = 0; i < A.size(); i++) {
            num = (num * 2 + A[i]) % 5;
            if(num % 5 == 0) flag.push_back(true);
            else flag.push_back(false);
        }
        return flag;
    }
};