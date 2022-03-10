//难度-简单
//简单题，考虑一下K比数组长的情况即可
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int cnt = A.size() - 1;
        while(K) {
            int q = K % 10;
            K /= 10;
            if(cnt < 0) {
                cnt++;
                A.insert(A.begin(), q);
            }
            else {
                if(A[cnt] + q >= 10) {
                    A[cnt] = (A[cnt] + q) % 10;
                    K += 1;
                }
                else A[cnt] += q;
            }
            cnt--;
        }
        return A;
    }
};