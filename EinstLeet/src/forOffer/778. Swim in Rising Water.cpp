//难度-困难
//考虑此时和雨水高度相等的单元格，考虑这个单元格的周围高度更低的单元格，把它们在并查集中进行合并
class UnionSet {
public:
    vector<int> parent;
    UnionSet(int n): parent(n) { iota(parent.begin(), parent.end(), 0); }
    int Find(int index) { return parent[index] == index ? parent[index] : parent[index] = Find(parent[index]); }
    void Union(int index1, int index2) {
        int root1 = Find(index1);
        int root2 = Find(index2);
        if(root1 == root2) return;
        parent[root2] = root1;
        return;
    }
    bool Connected(int index1, int index2) { return Find(index1) == Find(index2); }
};
class Solution {
public:
    int N;
    int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
    int swimInWater(vector<vector<int>>& grid) {
        N = grid.size();
        int size = N * N;
        map<int, int> mp;
        for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) mp[grid[i][j]] = i * N + j;
        UnionSet us(size);
        for(int i = 0; i < size; i++) {
            int x = mp[i] / N;
            int y = mp[i] % N;
            for(int j = 0; j < 4; j++) {
                int newx = x + dir[j][0];
                int newy = y + dir[j][1];
                if(inGrid(newx, newy) && grid[newx][newy] <= i) us.Union(mp[i], newx * N + newy);
                if(us.Connected(0, size - 1)) return i;
            }
        }
        return -1;
    }
    bool inGrid(int x, int y) { return x >= 0 && x < N && y >= 0 && y < N; }
};