//难度-困难
//暴力枚举
class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n = positions.size();
        vector<int> heights(n);
        for(int i = 0; i < n; i++) {
            int l1 = positions[i][0], r1 = positions[i][0] + positions[i][1] - 1;
            heights[i] = positions[i][1];
            for(int j = 0; j < i; j++) {
                int l2 = positions[j][0], r2 = positions[j][0] + positions[j][1] - 1;
                if(r1 >= l2 && r2 >= l1) heights[i] = max(heights[i], heights[j] + positions[i][1]);
            }
        }
        for(int i = 1; i < n; i++) heights[i] = max(heights[i], heights[i - 1]);
        return heights;
    }
};