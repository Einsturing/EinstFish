/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right) {
                int mid = nums[i] + nums[left] + nums[right];
                if(abs(mid - target) < abs(ans - target)) ans = mid;
                if(mid < target) left++;
                else if(mid > target) right--;
                else return mid;
            }
        }
        return ans;
    }
};
// @lc code=end

