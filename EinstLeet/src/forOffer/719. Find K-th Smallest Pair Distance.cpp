//难度-困难
//二分查找
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = nums.back() - nums.front();
        while(l <= r) {
            int mid = (l + r) / 2;
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                int i = lower_bound(nums.begin(), nums.begin() + j, nums[j] - mid) - nums.begin();
                cnt += j - i;
            }
            if(cnt >= k) r = mid - 1;
            else  l= mid + 1;
        }
        return l;
    }
};