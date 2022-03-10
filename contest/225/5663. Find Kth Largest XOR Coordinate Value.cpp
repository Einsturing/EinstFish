//难度-中等
//周赛第三题，计算每个位置的大小，丢到大小为k的优先队列里，根就是第k大的值
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(i == 0 && j == 0) matrix[i][j] = matrix[i][j];
                else if(i == 0) matrix[i][j] = matrix[i][j - 1] ^ matrix[i][j];
                else if(j == 0) matrix[i][j] = matrix[i - 1][j] ^ matrix[i][j];
                else matrix[i][j] = matrix[i][j - 1] ^ matrix[i - 1][j] ^ matrix[i - 1][j - 1] ^ matrix[i][j];
                if(pq.size() < k) pq.push(matrix[i][j]);
                else {
                    if(matrix[i][j] > pq.top()) {
                        pq.pop();
                        pq.push(matrix[i][j]);
                    }
                }
            }
        }
        return pq.top();
    }
};