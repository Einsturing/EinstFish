//难度-简单
//简单模拟题
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int r_nums = nums.size();
        int c_nums = nums[0].size();
        if(r_nums * c_nums != r * c) return nums;
        vector<int> rows;
        vector<vector<int>> res;
        int cnt = 0;
        for(int i = 0; i < r_nums; i++) {
            for(int j = 0; j < c_nums; j++) {
                rows.push_back(nums[i][j]);
                cnt++;
                if(cnt == c) {
                    res.push_back(rows);
                    cnt = 0;
                    rows.clear();
                }
            }
        }
        return res;
    }
};