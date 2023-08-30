//难度-中等
//并查集+kruskal最小生成树
class edge {
public:
    int id1;
    int id2;
    int weight;
    edge(int id1, int id2, int weight):id1(id1), id2(id2), weight(weight) {};
};
class UnionSet {
public:
    vector<int> parent;
    UnionSet(int n) {
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    int Find(int index) {
        if(parent[index] != index) return parent[index] = Find(parent[index]);
        return parent[index];
    }
    int Union(int index1, int index2) {
        int root1 = Find(index1);
        int root2 = Find(index2);
        if(root1 == root2) return false;
        parent[root2] = root1;
        return true;
    }
};
class Solution {
public:
    static bool cmp(const edge& a, const edge& b) { return a.weight < b.weight; }
    int minCostConnectPoints(vector<vector<int>>& points) {
        auto dis = [&](int x, int y) -> int { return abs(points[x][0] - points[y][0]) + abs(points[x][1] - points[y][1]); };
        int n  = points.size();
        vector<edge> v;
        UnionSet us(n);
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                v.emplace_back(i, j, dis(i, j));
            }
        }
        sort(v.begin(), v.end(), cmp);
        int ans = 0, num = 1;
        for(auto& [x, y, len] : v) {
            if(us.Union(x, y)) {
                ans += len;
                if(++num == n) break;
            }
        }
        return ans;
    }
};