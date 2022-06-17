//难度-简单
//模拟即可
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> tmp;
        int cnt = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] != 0) {
                tmp.emplace_back(arr[i]);
                cnt++;
            }
            else {
                tmp.emplace_back(0);
                tmp.emplace_back(0);
                cnt += 2;
            }
            if(cnt >= arr.size()) break;
        }
        if(cnt > arr.size()) tmp.pop_back();
        arr = tmp;
    }
};