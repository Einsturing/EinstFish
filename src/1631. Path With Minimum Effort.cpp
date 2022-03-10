//难度-中等
//将所有边排序并依次加入并查集。当加入一条权值为x的边之后，左上角和右下角变为连通状态，那么x即为答案。
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
    int res = 0;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        vector<tuple<int, int, int> > edges;
        for(int i = 0; i < row; i++) for(int j = 0; j < col; j++) {
            int id = i * col + j;
            if(i > 0) edges.emplace_back(id - col, id, abs(heights[i][j] - heights[i - 1][j]));
            if(j > 0) edges.emplace_back(id - 1, id, abs(heights[i][j] - heights[i][j - 1]));
        }
        sort(edges.begin(), edges.end(), [](const auto& e1, const auto& e2){
            auto&& [x1, y1, v1] = e1;
            auto&& [x2, y2, v2] = e2;
            return v1 < v2;
        });
        UnionSet us(row * col);
        for(const auto [x, y, v] : edges) {
            us.Union(x, y);
            if(us.Connected(0, row * col - 1)) {
                res = v;
                break;
            }
        }
        return res;
    }
};