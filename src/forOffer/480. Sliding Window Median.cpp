//难度-困难
//滑动窗口求中位数，用两个优先队列维护窗口里大小两部分，利用堆顶求中位数，用map记录某元素延迟删除次数，当它到堆顶时进行删除以免影响求中位数
class Solution {
public:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int> > large;
    unordered_map<int, int> delMp;
    double calMedian(int k) {
        if(k % 2) return small.top();
        else return ((double)small.top() + (double)large.top()) / 2;
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        for(int i = 0; i < k; i++) small.push(nums[i]);
        for(int i = 0; i < k / 2; i++) {
            large.push(small.top());
            small.pop();
        }
        vector<double> res{calMedian(k)};
        for(int i = k; i < nums.size(); i++) {
            int balance = 0;
            int left = nums[i - k];
            delMp[left]++;
            if(!small.empty() && left <= small.top()) balance--;
            else balance++;
            if(!small.empty() && nums[i] <= small.top()) {
                small.push(nums[i]);
                balance++;
            }
            else {
                large.push(nums[i]);
                balance--;
            }
            if(balance > 0) {
                large.push(small.top());
                small.pop();
            }
            if(balance < 0) {
                small.push(large.top());
                large.pop();
            }
            while(!small.empty() && delMp[small.top()] > 0) {
                delMp[small.top()]--;
                small.pop();
            }
            while(!large.empty() && delMp[large.top()] > 0) {
                delMp[large.top()]--;
                large.pop();
            }
            res.push_back(calMedian(k));
        }
        return res;
    }
};