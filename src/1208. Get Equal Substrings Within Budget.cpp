//难度-中等
//转换成计算数组和不超过某值的最长子数组的长度，再双指针
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int len = s.length();
        vector<int> diff(len, 0);
        for(int i = 0; i < len; i++) diff[i] = abs(s[i] - t[i]);
        int left = 0, right = 0, sum = 0, res = 0;
        while(right < len) {
            sum += diff[right];
            while(sum > maxCost) {
                sum -=diff[left];
                left++;
            }
            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }
};