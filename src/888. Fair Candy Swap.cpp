//难度-简单
//简单哈希表
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sumA = accumulate(A.begin(), A.end(), 0);
        int sumB = accumulate(B.begin(), B.end(), 0);
        int param = (sumA - sumB) / 2;
        set<int> sa(A.begin(), A.end());
        vector<int> res;
        for(auto i : B) {
            int x = i + param;
            if(sa.count(x) != 0) {
                res.push_back(x);
                res.push_back(i);
                break;
            }
        }
        return res;
    }
};