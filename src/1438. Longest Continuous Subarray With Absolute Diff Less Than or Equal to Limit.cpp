//难度-中等
//用两个双端队列分别维护最大值和最小值，保持队首之差满足条件
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int len = nums.size();
        int left = 0, right = 0;
        int res = 0;
        deque<int> qMax, qMin;
        while(right < len) {
            while(!qMax.empty() && qMax.back() < nums[right]) qMax.pop_back();
            while(!qMin.empty() && qMin.back() > nums[right]) qMin.pop_back();
            qMax.push_back(nums[right]);
            qMin.push_back(nums[right]);
            while(!qMax.empty() && !qMin.empty() && qMax.front() - qMin.front() > limit) {
                if(nums[left] == qMax.front()) qMax.pop_front();
                if(nums[left] == qMin.front()) qMin.pop_front();
                left++;
            }
            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }
};