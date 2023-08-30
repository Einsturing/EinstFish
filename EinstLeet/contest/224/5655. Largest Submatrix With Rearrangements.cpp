//难度-中等
//周赛第三题，太菜了所以没有思路，记录每个点及其上方的1的个数，转换为一维问题，对每一行排序找最大
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int res = 0;
        for(int i = 1; i < matrix.size(); i++) for(int j = 0; j < matrix[0].size(); j++)
                if(matrix[i][j] == 1) matrix[i][j] += matrix[i - 1][j];
        for(int i = 0; i < matrix.size(); i++) {
            sort(matrix[i].begin(), matrix[i].end());
            int len = matrix[i].size();
            for(int j = len - 1; j >= 0; j--) res = max(res, matrix[i][j] * (len - j));
        }
        return res;
    }
};