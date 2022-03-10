//难度-困难
//并查集+kruskal，先求最小生成树，再依次去除每条边求最小生成树，若不连通或值变大就是关键边，若值不变就是伪关键边
class UnionSet{
public:
    vector<int> parent;
    int cnt;
    UnionSet(int n): cnt(n) {
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    int Find(int index) {
        if(parent[index] != index) return parent[index] = Find(parent[index]);
        return parent[index];
    }
    bool Union(int index1, int index2) {
        int root1 = Find(index1);
        int root2 = Find(index2);
        if(root1 == root2) return false;
        parent[root2] = root1;
        cnt--;
        return true;
    }
};
class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        for(int i = 0; i <m; i++) edges[i].push_back(i);
        sort(edges.begin(), edges.end(), [](const auto& x, const auto& y) { return x[2] < y[2]; });
        UnionSet us(n);
        int val = 0;
        for(int i = 0; i < m; i++) if(us.Union(edges[i][0], edges[i][1])) val += edges[i][2];
        vector<vector<int>> res(2);
        for(int i = 0; i < m; i++) {
            UnionSet us2(n);
            int val2 = 0;
            for(int j = 0; j < m; j++) if(i != j && us2.Union(edges[j][0], edges[j][1])) val2 += edges[j][2];
            if(us2.cnt != 1 || (us2.cnt == 1 && val2 > val)) {
                res[0].push_back(edges[i][3]);
                continue;
            }
            us2 = UnionSet(n);
            us2.Union(edges[i][0], edges[i][1]);
            val2 = edges[i][2];
            for(int j = 0; j < m; j++) if(i != j && us2.Union(edges[j][0], edges[j][1])) val2 += edges[j][2];
            if(val2 == val) res[1].push_back(edges[i][3]);
        }
        return res;
    }
};