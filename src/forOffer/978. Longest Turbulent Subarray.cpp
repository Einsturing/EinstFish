//难度-中等
//滑动窗口统计最长即可
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int len = arr.size();
        int res = 1;
        for(int i = 0, j = 0; j < len - 1;) {
            if(i == j) {
                if(arr[i] == arr[i + 1]) i++;
                j++;
            }
            else {
                if(arr[j - 1] < arr[j] && arr[j] > arr[j + 1]) j++;
                else if(arr[j - 1] > arr[j] && arr[j] < arr[j + 1]) j++;
                else i = j;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};