//难度-困难
//图论题，反向思考，考虑补上被击碎的砖块以后，有多少个砖块因为这个补上的砖块而与屋顶的砖块相连，再使用并查集
class UnionSet {
public:
    vector<int> parent;
    vector<int> nums;
    UnionSet(int n) {
        parent.resize(n);
        nums.resize(n);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            nums[i] = 1;
        }
    }
    int Find(int index) {
        if(parent[index] != index) parent[index] = Find(parent[index]);
        return parent[index];
    }
    void Union(int index1, int index2) {
        int root1 = Find(index1);
        int root2 = Find(index2);
        if(root1 == root2) return;
        parent[root1] = root2;
        nums[root2] += nums[root1];
    }
    int getNums(int index) { 
        int root = Find(index);
        return nums[root];
    }
};

class Solution {
public:
    int rows;
    int cols;
    int dir[4][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
    bool outOfIndex(int i, int j) { return i < 0 || i >= rows || j < 0 || j >= cols; }
    int getIndex(int i, int j) { return i * cols + j; }
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        this->rows = grid.size();
        this->cols = grid[0].size();
        int size = rows * cols;
        UnionSet us(size + 1);
        vector<vector<int>> copy = grid;
        for(auto hit : hits) { copy[hit[0]][hit[1]] = 0; }
        for(int j = 0; j < cols; j++) { if(copy[0][j] == 1) us.Union(j, size); }
        for(int i = 1; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(copy[i][j] == 1) {
                    if(copy[i - 1][j] == 1) us.Union(getIndex(i, j), getIndex(i - 1, j));
                    if(j > 0 && copy[i][j - 1] == 1) us.Union(getIndex(i, j), getIndex(i, j - 1));
                }
            }
        }
        int len = hits.size();
        vector<int> res(len);
        for(int i = len - 1; i >=0; i--) {
            int x = hits[i][0];
            int y = hits[i][1];
            if(grid[x][y] == 0) continue;
            int begin = us.getNums(size);
            if(x == 0) us.Union(getIndex(x, y), size);
            for(int i = 0; i < 4; i++) {
                int newX = x + dir[i][0];
                int newY = y + dir[i][1];
                if(!outOfIndex(newX, newY) && copy[newX][newY] == 1) us.Union(getIndex(x, y), getIndex(newX, newY));
            }
            int now = us.getNums(size);
            res[i] = max(0, now - begin - 1);
            copy[x][y] = 1;
        }
        return res;
    }
};